<?php

/**
 * Created by PhpStorm.
 * User: HAUTRUONG
 * Date: 9/30/2016
 * Time: 4:55 PM
 */
class VMEntityController extends EntityAPIController {
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