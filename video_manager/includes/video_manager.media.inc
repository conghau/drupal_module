<?php

/**
 * Created by PhpStorm.
 * User: hautruong
 * Date: 28/09/2016
 * Time: 14:17
 */
class VMMedia {
  protected $data;
  protected $uri;
  protected $width;
  protected $height;
  private $yt_api;
  private $vm_api;

  public function __construct($api = array()) {
    $this->data = new stdClass;
    if (isset($api["yt_api"])) {
      $this->yt_api = $api["yt_api"];
    }
    if (isset($api["vm_api"])) {
      $this->vm_api = $api["vm_api"];
    }
  }

  /**
   * Import Video
   * @since  1.0
   *
   * @param $uri
   * @param int $width
   * @param int $height
   * @param string $error_message
   * @return object
   */
  public function import($uri, $width = 500, $height = 480, &$error_message='') {
    // Clean URL
    $uri = VMUtil::clean($uri, 3, TRUE);
    // Valid URL
    if (!VMUtil::is_url($uri)) {
      $error_message = 'Please enter a valid URL and make sure to include http:// or https://"';
      return FALSE;
//      return $this->out(array("error" => "Please enter a valid URL and make sure to include http:// or https://"));
    }
    $this->uri = $uri;
    $this->width = $width;
    $this->height = $height;
    // Check if file is an image
    if (in_array(VMUtil::extension($this->uri, FALSE), array(
      'jpg',
      'png',
      'gif'
    ))) {
      //$this->import_image();
      return $this->out();
    }
    // Analyze URL
    $uri = parse_url($uri);
    $uri = explode(".", $uri["host"]);
    $uri = array_reverse($uri);
    $host = $uri[1];
    // Check if Youtube
    if (in_array($host, array("youtube", "youtu", "youtube-nocookie"))) {
      $host = "youtube";
    }
    $host = "import_{$host}";
    // Use method
    if (method_exists(__CLASS__, $host)) {
      // Get Content
      $this->{$host}();
      return $this->out();
    }
    return $this->out(array("error" => "Provider not supported or video not available."));
  }

  /**
   * Youtube Data API
   * @since 1.5
   **/
  public function import_youtube($id = NULL) {
    if (is_null($id)) {
      // Match Youtube Link
      if (preg_match('%(?:youtube(?:-nocookie)?\.com/(?:[^/]+/.+/|(?:v|e(?:mbed)?)/|.*[?&]v=)|youtu\.be/)([^"&?/ ]{11})%i', $this->uri, $match)) {
        $id = $match[1];
      }
      else {
        return array("error" => "Sorry this video cannot be accessed for some reason.");
      }
    }

    $part = "snippet,contentDetails,statistics,topicDetails,status";
    $uri = "https://www.googleapis.com/youtube/v3/videos?key={$this->yt_api}&part=$part&id=$id";

    $json = VMUtil::http($uri);
    if (!$json) {
      return array("error" => "Sorry this video cannot be accessed for some reason.");
    }

    $json = json_decode($json);
    // Fix duration
    $start = new DateTime('@0'); // Unix epoch
    $start->add(new DateInterval($json->items[0]->contentDetails->duration));
    $seconds = $start->format('H') * 24;
    $seconds = $seconds + $start->format('i') * 60;
    $seconds = $seconds + $start->format('s');

    $this->data->title = $json->items[0]->snippet->title;
    $this->data->slug = VMUtil::slug($this->data->title);
    $this->data->id = $id;
    $this->data->duration = $seconds;
    $this->data->description = VMUtil::clean($json->items[0]->snippet->description, 3, TRUE);
    $this->data->thumb = "http://img.youtube.com/vi/$id/hqdefault.jpg";
    $this->data->size = $this->size($this->data->thumb);
    $this->data->tag = @implode(',', $json->items[0]->snippet->tags);
    $this->data->src = "//www.youtube-nocookie.com/embed/$id?showinfo=0&rel=0&iv_load_policy=3&modestbranding=1";
    $this->data->import = "Youtube";
      $this->data->views = $json->items[0]->statistics->viewCount;
      $this->data->likes = $json->items[0]->statistics->likeCount;
      $this->data->dis_likes =$json->items[0]->statistics->dislikeCount;
      $this->data->comments =$json->items[0]->statistics->commentCount;


  }

  /**
   * Image Size
   * @since  1.0
   *
   * @param $image
   * @param bool $array
   * @return array|string
   */
  public function size($image, $array = FALSE) {
    list($width, $height) = @getimagesize($image);
    if ($array) {
      return array("w" => $width, "h" => $height);
    }
    return "($width x $height)";
  }

  /**
   * Get Videos
   * @since  1.0
   *
   * @param null $response
   * @return object|\stdClass
   */
  public function out($response = NULL) {
    // Return Custom Response
    if (!is_null($response)) {
      return (object) $response;
    }
    // Generate Object
    if (!is_object($this->data)) {
      return (object) array("error" => "An unknown error has occured.");
    }
    if (!isset($this->data->src)) {
      return (object) array("error" => "An unknown error has occured.");
    }

    if (!isset($this->data->duration)) {
      $this->data->duration = "0";
    }
    $this->data->description = str_replace('"', "#&34;", $this->data->description);
    $this->data->title = str_replace('"', " 554 ", $this->data->title);

    if (!isset($this->data->custom_code)) {
      $this->data->code = "<iframe src='{$this->data->src}' width='{$this->width}' height='{$this->height}' frameborder='0' webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>";
    }
    else {
      $this->data->code = $this->data->custom_code;
    }
    return $this->data;
  }
}