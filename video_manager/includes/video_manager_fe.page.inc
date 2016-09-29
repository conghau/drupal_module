<?php
/**
 * Created by PhpStorm.
 * User: hautruong
 * Date: 29/09/2016
 * Time: 15:21
 */

function vm_view_video_page($slug, $unique_id) {
  $video = video_manager_load_first_by('unique_id', $unique_id);
  dsm($video);
  $data = array('video' => $video);
  return theme('vm_block_fe_views_video', $data);
}