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
     *
     * @return mixed|string
     */
    function vm_get_value($data, $field, $default_value = '') {
        $sub_fields = explode('.', $field);
        foreach ($sub_fields as $field) {
            if (is_array($data) && isset($data[$field])) {
                $data = $data[$field];
            } elseif (is_object($data) && isset($data->{$field})) {
                $data = $data->{$field};
            } else {
                $data = $default_value;
                break;
            }
        }
        return $data;
    }
}

if (!function_exists('vm_url')) {
    /**
     * Custom get url
     *
     * @param string $path
     * @param array $options
     *
     * @return string
     */
    function vm_url($path = '', $options = array('absolute' => TRUE)) {
        return url($path, $options);
    }
}