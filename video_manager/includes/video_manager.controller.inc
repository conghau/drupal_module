<?php
/**
 * Created by PhpStorm.
 * User: HAUTRUONG
 * Date: 9/30/2016
 * Time: 4:55 PM
 */

/**
 * @file custom entity controllor
 */
class VMEntityController extends EntityAPIController {
    /**
     * Override function create
     *
     * @param array $values
     *
     * @return entity
     */
    function create(array $values = array()) {
        $entity = parent::create($values);
        global $user;
        $entity->created_by = $user->uid;
        $entity->created_at = REQUEST_TIME;
        return $entity;
    }

    /**
     * Override function save
     *
     * @param $entity
     * @param DatabaseTransaction|NULL $transaction
     *
     * @return bool|int
     */
    function save($entity, DatabaseTransaction $transaction = NULL) {
        $result = FALSE;
        try {
            $result = parent::save($entity, $transaction);
        } catch (Exception $e) {
            watchdog('video_manager', json_encode(array('action' => 'save', 'error' => $e->getMessage(), 'data' => $entity)));
        }
        return $result;
    }
}