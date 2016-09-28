<?php

/**
 * Created by PhpStorm.
 * User: hautruong
 * Date: 28/09/2016
 * Time: 14:25
 */
class VMUtil {
  /**
   * Custom cURL Function
   * @since 1.0
   **/
  public static function http($url, $option = array()) {
    if (ini_get('allow_url_fopen') && !isset($option["post"])) {
      return @file_get_contents($url);
    }
    if (in_array('curl', get_loaded_extensions())) {
      $curl = curl_init();
      curl_setopt($curl, CURLOPT_URL, $url);
      if (isset($option["post"]) && isset($option["data"]) && is_array($option["data"])) {
        $fields = "";
        //url-ify the data for the POST
        foreach ($option["data"] as $key => $value) {
          $fields .= $key . '=' . $value . '&';
        }

        rtrim($fields, '&');
        curl_setopt($curl, CURLOPT_POST, count($option["data"]));
        curl_setopt($curl, CURLOPT_POSTFIELDS, $fields);
      }
      curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
      //curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
      $resp = curl_exec($curl);
      curl_close($curl);
      return $resp;
    }
    return FALSE;
  }

  /**
   * Generate slug
   * @param string
   * @return slug
   */

  public static function slug($text, $replace = array(), $delimiter = '-') {
    $str = $text;
    if (!empty($replace)) {
      $str = str_replace((array) $replace, ' ', $str);
    }

    $text = $str;
    static $translit = array(
      'a' => '/[ÀÁÂẦẤẪẨÃĀĂẰẮẴȦẲǠẢÅÅǺǍȀȂẠẬẶḀĄẚàáâầấẫẩãāăằắẵẳȧǡảåǻǎȁȃạậặḁą]/u',
      'b' => '/[ḂḄḆḃḅḇ]/u',
      'c' => '/[ÇĆĈĊČḈçćĉċčḉ]/u',
      'd' => '/[ÐĎḊḌḎḐḒďḋḍḏḑḓð]/u',
      'e' => '/[ÈËÉĒĔĖĘĚȄȆȨḔḖḘḚḜẸẺẼẾỀỂỄỆèéëēĕėęěȅȇȩḕḗḙḛḝẹẻẽếềểễệ]/u',
      'f' => '/[Ḟḟ]/u',
      'g' => '/[ĜĞĠĢǦǴḠĝğġģǧǵḡ]/u',
      'h' => '/[ĤȞḢḤḦḨḪĥȟḣḥḧḩḫẖ]/u',
      'i' => '/[ÌÏĨĪĬĮİǏȈȊḬḮỈỊiìïĩīĭįǐȉȋḭḯỉị]/u',
      'j' => '/[Ĵĵǰ]/u',
      'k' => '/[ĶǨḰḲḴKķǩḱḳḵ]/u',
      'l' => '/[ĹĻĽĿḶḸḺḼĺļľŀḷḹḻḽ]/u',
      'm' => '/[ḾṀṂḿṁṃ]/u',
      'n' => '/[ÑŃŅŇǸṄṆṈṊñńņňǹṅṇṉṋ]/u',
      'o' => '/[ÒÖŌŎŐƠǑǪǬȌȎȪȬȮȰṌṎṐṒỌỎỐỒỔỖỘỚỜỞỠỢØǾòöōŏőơǒǫǭȍȏȫȭȯȱṍṏṑṓọỏốồổỗộớờởỡợøǿ]/u',
      'p' => '/[ṔṖṕṗ]/u',
      'r' => '/[ŔŖŘȐȒṘṚṜṞŕŗřȑȓṙṛṝṟ]/u',
      's' => '/[ŚŜŞŠȘṠṢṤṦṨſśŝşšșṡṣṥṧṩ]/u',
      'ss' => '/[ß]/u',
      't' => '/[ŢŤȚṪṬṮṰţťțṫṭṯṱẗ]/u',
      'th' => '/[Þþ]/u',
      'u' => '/[ÙŨŪŬŮŰŲƯǓȔȖṲṴṶṸṺỤỦỨỪỬỮỰùũūŭůűųưǔȕȗṳṵṷṹṻụủứừửữựµ]/u',
      'v' => '/[ṼṾṽṿ]/u',
      'w' => '/[ŴẀẂẄẆẈŵẁẃẅẇẉẘ]/u',
      'x' => '/[ẊẌẋẍ×]/u',
      'y' => '/[ÝŶŸȲẎỲỴỶỸýÿŷȳẏẙỳỵỷỹ]/u',
      'z' => '/[ŹŻŽẐẒẔźżžẑẓẕ]/u',
      //combined letters and ligatures:
      'ae' => '/[ÄǞÆǼǢäǟæǽǣ]/u',
      'oe' => '/[Œœ]/u',
      'dz' => '/[ǄǅǱǲǆǳ]/u',
      'ff' => '/[ﬀ]/u',
      'fi' => '/[ﬃﬁ]/u',
      'ffl' => '/[ﬄﬂ]/u',
      'ij' => '/[Ĳĳ]/u',
      'lj' => '/[Ǉǈǉ]/u',
      'nj' => '/[Ǌǋǌ]/u',
      'st' => '/[ﬅﬆ]/u',
      'ue' => '/[ÜǕǗǙǛüǖǘǚǜ]/u',
      //currencies:
      'eur' => '/[€]/u',
      'cents' => '/[¢]/u',
      'lira' => '/[₤]/u',
      'dollars' => '/[$]/u',
      'won' => '/[₩]/u',
      'rs' => '/[₨]/u',
      'yen' => '/[¥]/u',
      'pounds' => '/[£]/u',
      'pts' => '/[₧]/u',
      //misc:
      'degc' => '/[℃]/u',
      'degf' => '/[℉]/u',
      'no' => '/[№]/u',
      'tm' => '/[™]/u'
    );
    //do the manual transliteration first
    $str = preg_replace(array_values($translit), array_keys($translit), $str);

    //flatten the text down to just a-z0-9 and dash, with underscores instead of spaces
    $str = preg_replace(//remove punctuation  //replace non a-z //deduplicate //trim underscores from start & end
      array('/\p{P}/u', '/[^A-Za-z0-9]/', '/-{2,}/', '/^-|-$/'), array(
      '-',
      '-',
      '-',
      '-'
    ),

      //attempt transliteration with PHP5.4's transliteration engine (best):
      //(this method can handle near anything, including converting chinese and arabic letters to ASCII.
      // requires the 'intl' extension to be enabled)
      function_exists('transliterator_transliterate') ? transliterator_transliterate(//split unicode accents and symbols, e.g. "Å" > "A°":
        'NFKD; ' . //convert everything to the Latin charset e.g. "ま" > "ma":
        //(splitting the unicode before transliterating catches some complex cases,
        // such as: "㏳" >NFKD> "20日" >Latin> "20ri")
        'Latin; ' . //because the Latin unicode table still contains a large number of non-pure-A-Z glyphs (e.g. "œ"),
        //convert what remains to an even stricter set of characters, the US-ASCII set:
        //(we must do this because "Latin/US-ASCII" alone is not able to transliterate non-Latin characters
        // such as "ま". this two-stage method also means we catch awkward characters such as:
        // "㏀" >Latin> "kΩ" >Latin/US-ASCII> "kO")
        'Latin/US-ASCII; ' . //remove the now stand-alone diacritics from the string
        '[:Nonspacing Mark:] Remove; ' . //change everything to lowercase; anything non A-Z 0-9 that remains will be removed by
        //the letter stripping above
        'Lower', $str)

        //attempt transliteration with iconv: <php.net/manual/en/function.iconv.php>
        : strtolower(function_exists('iconv') ? str_replace(array(
        "'",
        '"',
        '`',
        '^',
        '~'
      ), '', strtolower(//note: results of this are different depending on iconv version,
      //      sometimes the diacritics are written to the side e.g. "ñ" = "~n", which are removed
        iconv('UTF-8', 'US-ASCII//IGNORE//TRANSLIT', $str))) : $str));

    //old iconv versions and certain inputs may cause a nullstring. don't allow a blank response
    if (!$str || $str == "_" || $str == "-") {
      $str = preg_replace("/[^A-Za-z0-9 -]/", '', $text);
      $str = preg_replace("/[\/_|+ -]+/", $delimiter, $str);
      $str = str_replace("'", "", $str);
      $str = str_replace('"', '', $str);
      $str = strtolower(rtrim(trim($str, '-'), '-'));
      if (empty($str) || $str == "_" || $str == "-") {
        return self::strrand(5);
      }
      else {
        return $str;
      }
    }
    else {
      return $str;
    }
  }

  /**
   * Generate api or random string
   *
   * @param int $length
   * @param string $api
   * @return string
   */
  public static function strrand($length = 12, $api = '') {
    $use = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    srand((double) microtime() * 1000000);
    for ($i = 0; $i < $length; $i++) {
      $api .= $use[rand() % strlen($use)];
    }
    return $api;
  }

  /**
   * Clean a string
   *
   * @param $string
   * @param string $level (1=lowest,2,3=highest)
   * @param bool $chars
   * @param string $leave
   * @return cleaned string
   */
  public static function clean($string, $level = '1', $chars = FALSE, $leave = '') {
    if (is_array($string)) {
      return array_map("self::clean", $string);
    }

    $string = preg_replace('/<script[^>]*>([\s\S]*?)<\/script[^>]*>/i', '', $string);
    switch ($level) {
      case '4':
        if (empty($leave)) {
          $search = array(
            '@<script[^>]*?>.*?</script>@si',
            '@<style[^>]*?>.*?</style>@siU'
          );
          $string = preg_replace($search, '', $string);
        }
        if ($chars) {
          if (phpversion() >= 5.4) {
            $string = htmlspecialchars($string, ENT_QUOTES | ENT_HTML5, "UTF-8");
          }
          else {
            $string = htmlspecialchars($string, ENT_QUOTES, "UTF-8");
          }
        }
        break;
      case '3':
        if (empty($leave)) {
          $search = array(
            '@<script[^>]*?>.*?</script>@si',
            '@<[\/\!]*?[^<>]*?>@si',
            '@<style[^>]*?>.*?</style>@siU',
            '@<![\s\S]*?--[ \t\n\r]*>@'
          );
          $string = preg_replace($search, '', $string);
        }
        $string = strip_tags($string, $leave);
        if ($chars) {
          if (phpversion() >= 5.4) {
            $string = htmlspecialchars($string, ENT_QUOTES | ENT_HTML5, "UTF-8");
          }
          else {
            $string = htmlspecialchars($string, ENT_QUOTES, "UTF-8");
          }
        }
        break;
      case '2':
        $string = strip_tags($string, '<b><i><s><p><u><strong><span>');
        break;
      case '1':
        $string = strip_tags($string, '<b><i><s><u><strong><a><pre><code><p><div><span>');
        break;

    }
    if (!preg_match('!nofollow!', $string)) {
      $string = str_replace('href=', 'rel="nofollow" href=', $string);
    }
    return trim($string);
  }

  /**
   * Validate URLs
   * @since 1.0
   *
   * @param $url
   * @return bool
   */
  public static function is_url($url) {
    if (preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i", $url) && filter_var($url, FILTER_VALIDATE_URL)) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Get extension
   *
   * @param $file
   * @param bool $dot
   * @return mixed|string
   */
  public static function extension($file, $dot = TRUE) {
    return $dot ? strrchr($file, ".") : str_replace(".", "", strrchr($file, "."));
  }
}