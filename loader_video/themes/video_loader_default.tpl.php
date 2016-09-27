<?php
/**
 * Created by PhpStorm.
 * User: hautruong
 * Date: 27/09/2016
 * Time: 10:50
 */

$attrs = '';
if (!empty($autoplay)) {
  $attrs .= ' autoplay="autoplay"';
}
if (!empty($poster)) {
  $attrs .= ' poster="'. check_plain($poster) .'"';
}
if (!empty($loop)) {
  $attrs .= ' loop="loop"';
}
if (empty($hidecontrols)) {
  $attrs .= ' controls="controls"';
}
if (!empty($preload) && ($preload === 'none' || $preload === 'auto' || $preload === 'metadata')) {
  $attrs .= ' preload="' . $preload . '"';
}

if(!empty($class)) {
  $class .= ' video-js vjs-default-skin';
}
else {
  $class = 'video-js vjs-default-skin';
}
if (!empty($items)): ?>
<!--  <video id="--><?php //print $player_id; ?><!---video" data-setup="{}" class="--><?php //print htmlspecialchars($class); ?><!--" width="--><?php //(isset($width) ? print $width: 640); ?><!--" height="--><?php //(isset($height))?print $height: 480; ?><!--"--><?php //echo $attrs; ?><!-->-->
<!--    --><?php //foreach ($items as $item): ?>
<!--      <source src="--><?php //print check_plain(file_create_url($item['uri'])) ?><!--" type="--><?php //isset($item['videotype']) ? print check_plain($item['videotype']) : print 'video/youtube'?><!--" />-->
<!--    --><?php //endforeach; ?>
<!--<!--    -->--><?php ////foreach ($tracks as $track):
////      $default = $track['default'] ? ' default="default"' : '';
////      ?>
<!--<!--      <track src="-->--><?php ////print check_plain(file_create_url($track['uri'])) ?><!--<!--" type="-->--><?php ////print check_plain($track['filemime']) ?><!--<!--" kind="-->--><?php ////print check_plain($track['kind']) ?><!--<!--" label="-->--><?php ////print check_plain($track['label']) ?><!--<!--" srclang="-->--><?php ////print check_plain($track['langcode']) ?><!--<!--"-->--><?php ////print $default; ?><!--<!-- />-->-->
<!--<!--    -->--><?php ////endforeach; ?>
<!--  </video>-->
  <video
    id="vid1"
    class="video-js vjs-default-skin"
    controls
    poster="http://cdn.wonderfulengineering.com/wp-content/uploads/2016/01/nature-wallpapers-9.jpg"
    width="640" height="264"
    data-setup='{ "techOrder": ["youtube"], "sources": [{ "type": "video/youtube", "src": "<?php print check_plain(file_create_url($items[0]['uri'])) ?>"}], "youtube": { "ytControls": 2 } }'
  >
  </video>
<?php endif;

echo print check_plain(file_create_url($items[0]['uri']));