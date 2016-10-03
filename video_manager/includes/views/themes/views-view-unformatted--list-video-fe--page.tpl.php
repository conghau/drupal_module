<?php
/**
 * Created by PhpStorm.
 * User: HAUTRUONG
 * Date: 10/2/2016
 * Time: 5:05 AM
 */
?>
<div class="vm-views-list-video-fe">
    <?php if (!empty($title)): ?>
        <h3><?php print $title; ?></h3>
    <?php endif; ?>
    <?php foreach ($rows as $id => $row): ?>
        <div<?php if ($classes_array[$id]) {
            print ' class="' . $classes_array[$id] . ' col-sm-' . intval(12 / variable_get('number_item_for_row_list_fe_desktop', 3)) . '"';
        } ?>>

            <?php print $row; ?>
        </div>
    <?php endforeach; ?>
</div>
<div style="clear: both"></div>
