<?php
/**
 * Created by PhpStorm.
 * User: hautruong
 * Date: 27/09/2016
 * Time: 13:04
 */

$element = $variables['element'];
dsm($element);
dsm($variables);
if (isset($element['#file']->uri)) {
  $output = '<div id="edit-logo-ajax-wrapper"><div class="form-item form-type-managed-file form-item-logo"><span class="file">';
  $output .= '<img height="50px" src="' . file_create_url($element['#file']->uri) . '" />';
  $output .= '</span><input type="submit" id="edit-' . $element['#name'] . '-remove-button" name="' . $element['#name'] . '_remove_button" value="Remove" class="form-submit ajax-processed">';
  $output .= '<input type="hidden" name="' . $element['#name'] . '[fid]" value="' . $element['#file']->fid . '">';

  return $output;
}