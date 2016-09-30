<?php
/**
 * Created by PhpStorm.
 * User: hautruong
 * Date: 28/09/2016
 * Time: 16:00
 */

if (!function_exists('vm_get_value')) {

  /**
   * vm get value
   *
   * @param $data
   * @param $field
   * @param string $default_value
   * @return mixed|string
   */
  function vm_get_value($data, $field, $default_value = '') {
    if (is_array($data)) {
      return isset($data[$field]) ? ($data[$field]) : $default_value;
    }

    if (is_object($data)) {
      return isset($data->{$field}) ? ($data->{$field}) : $default_value;
    }
    return $default_value;
  }
}

if (!function_exists('vm_url')) {
  /**
   * Custom get url
   * 
   * @param string $path
   * @param array $options
   * @return string
   */
  function vm_url($path = '', $options = array('absolute' => TRUE)) {
    return url($path, $options);
  }
}