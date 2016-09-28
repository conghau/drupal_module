<?php
/**
 * Created by PhpStorm.
 * User: hautruong
 * Date: 28/09/2016
 * Time: 11:24
 */

/**
 * Init form add video
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function vm_video_add_form($form, &$form_state) {
  return $form;
}

function vm_video_import_form($form, &$form_state) {
  $video_uri = isset($_GET['video_uri']) ? $_GET['video_uri'] : '';

  if ('' === $video_uri) {
    _vm_video_manager_form_submit_url($form);
    return $form;
  }
  _vm_video_manage_form_parser_url($form, $video_uri);
  return $form;

}

function _vm_video_manager_form_submit_url(&$form) {
  $form['video_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => '',
    '#description' => t('URL to the video (including http://)'),
    '#required' => TRUE,
    '#weight' => 1,
  );

  $form['action'] = array(
    '#weight' => 2,
  );
  $form['action']['get_video'] = array(
    '#type' => 'submit',
    '#name' => 'get_video',
    '#value' => t('Get Video'),
    '#weight' => 1,
  );

  $form['guide'] = array(
    '#type' => 'fieldset',
    '#title' => t('List of supported providers'),
    '#weight' => 3,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE
  );
  $form['guide'] = array(
    '#type' => 'fieldset',
    '#title' => t('List of supported providers'),
    '#weight' => 3,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE
  );
}


function _vm_video_manage_form_parser_url(&$form, $video_uri) {
  $import = new VMMedia(array(
    'yt_api' => 'AIzaSyAQ-fZygHMUNd_Jxqcq4OSLxBB14nnb3XI',
    'vm_api' => ''
  ));
  $error_message = '';
  $media = $import->import($video_uri, '100%', '500', $error_message);
  if (!$media) {
    drupal_set_message($error_message, 'error');
    drupal_goto('video-manager/video/import');
  }

  $target_textfield = array(
    'title' => 'Title',
    'slug' => 'Media permalink',
    'duration' => 'Media Duration',
    'tag' => 'Tags'
  );

  foreach ($target_textfield as $field => $label) {
    $form[$field] = array(
      '#type' => 'textfield',
      '#title' => t($label),
      '#default_value' => vm_get_value($media, $field, ''),
      '#required' => TRUE,
    );
  }

  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => vm_get_value($media, 'description', '')
  );

  $form['video_preview'] = array(
    '#type' => 'item',
    '#title' => t('Video Preview'),
    '#markup' => vm_get_value($media, 'code', '')
  );

  $form['embed'] = array(
    '#type' => 'textarea',
    '#title' => t('Embed Code'),
    '#default_value' => vm_get_value($media, 'code', '')
  );

  $form['thumb'] = array(
    '#type' => 'item',
    '#title' => t('Image Thumb ') . vm_get_value($media, 'size', ''),
    '#markup' => '<img src="' . vm_get_value($media, 'thumb', '') . '" width=180 />',
  );

  $form['action']['import'] = array(
    '#type' => 'submit',
    '#name' => 'import_media',
    '#value' => t('Import Media'),
  );
}


function vm_video_import_form_submit($form, &$form_state) {
  dsm($form_state['triggering_element']['#name']);
  $video_uri = $form_state['values']['video_uri'];
  $_GET['video_uri'] = $video_uri;
}