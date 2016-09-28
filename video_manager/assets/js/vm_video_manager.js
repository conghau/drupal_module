/**
 * Created by hautruong on 28/09/2016.
 */
;(function ($, Drupal) {
    Drupal.behaviors.video_manager_behavior = {
        attach: function (context, settings) {
            $tagControl = jQuery('#vm-video-import-form #edit-tag');
            if (0 != $tagControl.length) {
                jQuery('#edit-tag').tagsInput({
                    'width': '100%',
                    'height': '64px',
                    'minChars': 3
                });
            }
        }
    }

})(jQuery, Drupal);