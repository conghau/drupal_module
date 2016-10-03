<?php
/**
 * Created by PhpStorm.
 * User: hautruong
 * Date: 30/09/2016
 * Time: 14:01
 */

/**
 * Init form config setting
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function vm_video_manager_setting_form($form, &$form_state) {

    $form ['setting_form'] = array(
        '#type' => 'vertical_tabs',
    );
    // This is the field fieldset.
    $form['common'] = array(
        '#type' => 'fieldset',
        '#title' => t('Common Config'),
        '#collapsible' => TRUE,
        '#description' => t('Common Config.'),
        '#group' => 'setting_form'
    );

    // Adding a simple textarea.
    $form['common']['mailbody'] = array(
        '#type' => 'textarea',
        '#required' => TRUE,
        '#default_value' => 'Default',
        '#title' => t('Contact mail.'),
        '#description' => t('Body text when a new comment is posted by users.'),
        '#group' => 'setting_form'
    );
    $form['FE'] = array(
        '#type' => 'fieldset',
        '#title' => t('Config for view FE'),
        '#collapsible' => TRUE,
        '#description' => t('Config for view FE.'),
        '#group' => 'setting_form'
    );
    $form ['FE']['number_item_for_row_list_fe_desktop'] = array(
        '#type' => 'select',
        '#title' => t('Number media for 1 rows in screen desktop'),
        '#options' => array('1' => t('1 item'), '2' => t('2 item'), '3' => t('3 item'), '4' => t('4 item'), '6' => t('6 item'), '12' => t('12 item')),
        '#default_value' => variable_get('number_item_for_row_list_fe_desktop', 3),
        '#group' => 'setting_form'
    );
    $form ['FE']['number_item_for_row_list_fe_mobile'] = array(
        '#type' => 'select',
        '#title' => t('Number media for 1 rows in screen desktop'),
        '#options' => array('1' => t('1 item'), '2' => t('2 item'), '3' => t('3 item'), '4' => t('4 item'), '6' => t('6 item'), '12' => t('12 item')),
        '#default_value' => variable_get('number_item_for_row_list_fe_mobile', 3),
        '#group' => 'setting_form'
    );

    $form ['FE']['custom_class_for_view'] = array(
        '#type' => 'textfield',
        '#title' => t('Custom Class For View'),
        '#default_value' => variable_get('custom_class_for_view', ''),
        '#group' => 'setting_form'
    );
    $form ['FE']['allow_user_font_awesome'] = array(
        '#type' => 'checkbox',
        '#title' => t('Allow User Font Awesome'),
        '#default_value' => variable_get('allow_user_font_awesome', 1),
        '#group' => 'setting_form'
    );
    $form ['FE']['allow_user_bootstrap'] = array(
        '#type' => 'checkbox',
        '#title' => t('Allow User Bootstrap'),
        '#default_value' => variable_get('allow_user_bootstrap', 1),
        '#group' => 'setting_form'
    );
    $form ['FE']['path_of_file_custom_css'] = array(
        '#type' => 'textarea',
        '#title' => t('Path of file custom CSS'),
        '#default_value' => variable_get('path_of_file_custom_css', ''),
        '#description' => t('File Custom CSS Must be inside module video_manager, suggest put in to /video_manager/assets/css/[your_file], enter if have more than one file css'),
        '#group' => 'setting_form'
    );
    $form ['FE']['path_of_file_custom_js'] = array(
        '#type' => 'textfield',
        '#title' => t('Path of file custom JS'),
        '#default_value' => variable_get('path_of_file_custom_js', ''),
        '#description' => t('File Custom Js Must be inside module video_manager, suggest put in to /video_manager/assets/js/[your_file]'),
        '#group' => 'setting_form'
    );


    $form = system_settings_form($form);
    return $form;
}