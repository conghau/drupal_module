<?php
/**
 * Created by PhpStorm.
 * User: HAUTRUONG
 * Date: 10/3/2016
 * Time: 4:31 PM
 */

/**
 * Implements hook_views_default_views().
 */
function video_manager_fe_views_default_views() {
    $views = array();
    $views['list_video_fe'] = vm_list_video();
    return $views;
}

function vm_list_video() {
    $view = new view();
    $view->name = 'list_video_fe';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'vm_video_manager';
    $view->human_name = 'List Video FE';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'List Video FE';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = (variable_get('number_row_for_list_fe_desktop', 3) * variable_get('number_item_for_row_list_fe_desktop', 3));
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['row_plugin'] = 'fields';
    /* Field: Video Manager Entity: Thumb */
    $handler->display->display_options['fields']['thumb']['id'] = 'thumb';
    $handler->display->display_options['fields']['thumb']['table'] = 'vm_video_manager';
    $handler->display->display_options['fields']['thumb']['field'] = 'thumb';
    /* Field: Video Manager Entity: Video manager entity ID */
    $handler->display->display_options['fields']['id']['id'] = 'id';
    $handler->display->display_options['fields']['id']['table'] = 'vm_video_manager';
    $handler->display->display_options['fields']['id']['field'] = 'id';
    /* Field: Video Manager Entity: Dis_likes */
    $handler->display->display_options['fields']['dis_likes']['id'] = 'dis_likes';
    $handler->display->display_options['fields']['dis_likes']['table'] = 'vm_video_manager';
    $handler->display->display_options['fields']['dis_likes']['field'] = 'dis_likes';
    $handler->display->display_options['fields']['dis_likes']['label'] = 'Dis likes';
    /* Field: Video Manager Entity: Likes */
    $handler->display->display_options['fields']['likes']['id'] = 'likes';
    $handler->display->display_options['fields']['likes']['table'] = 'vm_video_manager';
    $handler->display->display_options['fields']['likes']['field'] = 'likes';
    /* Field: Video Manager Entity: Slug */
    $handler->display->display_options['fields']['slug']['id'] = 'slug';
    $handler->display->display_options['fields']['slug']['table'] = 'vm_video_manager';
    $handler->display->display_options['fields']['slug']['field'] = 'slug';
    /* Field: Video Manager Entity: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'vm_video_manager';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    /* Field: Video Manager Entity: Unique_id */
    $handler->display->display_options['fields']['unique_id']['id'] = 'unique_id';
    $handler->display->display_options['fields']['unique_id']['table'] = 'vm_video_manager';
    $handler->display->display_options['fields']['unique_id']['field'] = 'unique_id';
    /* Field: Video Manager Entity: Uri */
    $handler->display->display_options['fields']['uri']['id'] = 'uri';
    $handler->display->display_options['fields']['uri']['table'] = 'vm_video_manager';
    $handler->display->display_options['fields']['uri']['field'] = 'uri';
    /* Field: Video Manager Entity: Views */
    $handler->display->display_options['fields']['views']['id'] = 'views';
    $handler->display->display_options['fields']['views']['table'] = 'vm_video_manager';
    $handler->display->display_options['fields']['views']['field'] = 'views';

    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'vm/video';
    return $view;
}