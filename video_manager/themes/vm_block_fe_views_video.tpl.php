<?php
/**
 * Created by PhpStorm.
 * User: hautruong
 * Date: 29/09/2016
 * Time: 15:11
 */
?>
<div class="col-md-8 content video" id="vm_view_video">
  <div class="video-player">
    <?php print vm_get_value($video, 'embed') ?>
  </div><!--/#video-player -->
  <div class="panel panel-default">
    <div class="video-info panel-body" itemprop="video" itemscope=""
         itemtype="http://schema.org/VideoObject">
      <h2 itemprop="name">
        <?php print vm_get_value($video, 'title') ?>

      </h2>
      <meta itemprop="description"
            content="<?php print vm_get_value($video, 'description') ?>">
      <meta itemprop="thumbnailUrl"
            content="<?php print vm_get_value($video, 'thumb') ?>">
      <meta itemprop="embedURL" content="http://dailimeo.com/embed/MQgT2">
      <div class="row">
        <div class="col-xs-8 col-md-9">
          <div class="video-author" data-id="1">
            <!-- Author Scheme -->
                  <span itemprop="author" itemscope=""
                        itemtype="http://schema.org/Person">
                    <meta itemprop="url"
                          content="http://dailimeo.com/user/dailimeo">
                    <meta itemprop="image"
                          content="http://dailimeo.com/content/user/AgEgijgg_avatar.jpg">        
                    <meta itemprop="name" content="Dailimeo">
                  </span>
            <!-- Author Scheme -->
            <a href="http://dailimeo.com/user/dailimeo" title="Dailimeo"><img
                src="http://dailimeo.com/content/user/AgEgijgg_avatar.jpg"
                alt="Dailimeo" class="video-author-avatar"></a>
          </div>
          <strong class="video-author-name"><a
              href="http://dailimeo.com/user/dailimeo">Dailimeo</a></strong>
          <a href="#subscribe" id="this-subscribe" data-action="subscribe"
             data-data="[&quot;id&quot;:1]"
             class="btn btn-danger btn-xs this-action subscribe this-tooltip"
             data-content="Subscribe">
            Subscribe </a>
          <span class="bubble bubble-left">0</span>
        </div>

        <div class="col-xs-4 col-md-3 stats" itemprop="aggregateRating"
             itemscope="" itemtype="http://schema.org/AggregateRating">
          <meta itemprop="ratingValue" content="0">
          <meta itemprop="ratingCount" content="0">
          599
          <small>views</small>
          <p>
            <span class="fa fa-thumbs-up"></span> 0&nbsp;&nbsp;
            <span class="fa fa-thumbs-down"></span> 0 </p></div><!--/.stats -->
      </div>
    </div><!--/.video-info -->
    <div class="video-option">
      <ul class="share panel-body">
        <li><a href="#like" id="this-like-39" class="this-action this-tooltip"
               data-content="Like" data-action="like"
               data-data="[&quot;id&quot;:39, &quot;check&quot;:1]"><span
              class="fa fa-thumbs-up"></span> Like</a></li>

        <li><a href="#dislike" id="this-dislike-39"
               class="this-action this-tooltip" data-content="Dislike"
               data-action="dislike"
               data-data="[&quot;id&quot;:39, &quot;check&quot;:1]"><span
              class="fa fa-thumbs-down"></span></a></li>

        <li class="right"><a href="" id="this-report"
                             class="this-action this-tooltip"
                             data-content="Report this page"
                             title="Report this page" data-action="report"
                             data-data="[&quot;id&quot;:39, &quot;check&quot;:&quot;media&quot;]"><span
              class="fa fa-flag"></span></a></li>

        <li class="right"><a href="#fav" id="this-addto"
                             class="this-toggle toggle" data-target=".addto">Add
            to</a></li>

        <li class="right"><a href="#share" id="share" class="this-toggle toggle"
                             data-target=".share_content">Share</a></li>
      </ul><!--/.share-->
      <hr>
      <div class="addto this-hide">
        <div class="row">
          <div class="col-md-4">
            <a href="#addto" id="this-addtofav" class="this-action this-tooltip"
               data-content="Add to Favorite" data-action="addtofav"
               data-data="[&quot;id&quot;:39, &quot;check&quot;:1]"><span
                class="fa fa-heart"></span> Add to Favorite</a>
          </div>
          <div class="col-md-8">
            <div class="panel panel-default" id="user-playlist">
              <div class="panel-heading">
                My Playlists
              </div>
              <div class="panel-body">
                <ul id="playlists-list">
                </ul>
              </div>
            </div>
          </div>
        </div>
        <hr>
      </div>
      <div class="share_content">
        <div class="panel-body">
          <div class="social-media">
            <a
              href="http://www.facebook.com/sharer.php?u=http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2"
              target="_blank" class="popup"><span class="fa fa-facebook"></span></a><a
              href="http://twitter.com/share?url=http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2&amp;text=Lion+takes+a+bite+out+of+sports+car"
              target="_blank" class="popup"><span class="fa fa-twitter"></span></a><a
              href="https://plus.google.com/share?url=http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2"
              target="_blank" class="popup"><span
                class="fa fa-google"></span></a><a
              href="http://www.digg.com/submit?url=http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2"
              target="_blank" class="popup"><span class="fa fa-digg"></span></a><a
              href="http://reddit.com/submit?url=http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2&amp;title=Lion+takes+a+bite+out+of+sports+car"
              target="_blank" class="popup"><span
                class="fa fa-reddit"></span></a><a
              href="http://www.linkedin.com/shareArticle?mini=true&amp;url=http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2"
              target="_blank" class="popup"><span class="fa fa-linkedin"></span></a><a
              href="http://www.stumbleupon.com/submit?url=http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2&amp;title=Lion+takes+a+bite+out+of+sports+car"
              target="_blank" class="popup"><span
                class="fa fa-stumbleupon"></span></a></div>
          <div id="shorturl">
            <div class="row">
              <div class="col-sm-8">
                <input class="form-control this-select" id="shortlink"
                       value="http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2"
                       type="text">
              </div>
              <div class="col-sm-4 text-right">
                <a href="#short" data-type="system"
                   data-short="http://dailimeo.com/v/MQgT2"
                   class="btn btn-primary btn-sm shorten"><span
                    class="fa fa-link"></span> Short Link</a>
                <a href="#embed" class="this-toggle btn btn-info btn-sm"
                   data-target="#embed"><span class="fa fa-code"></span>
                  Embed</a>
              </div>
            </div>
          </div>
          <div id="embed" class="this-hide">
            <textarea class="form-control this-select" id="embed-code" rows="4">&lt;iframe src='http://dailimeo.com/embed/MQgT2' frameborder='0' width='550' height='350' scrolling='no' allowfullscreen&gt;&lt;/iframe&gt;&lt;p&gt;&lt;a style='color: #000; text-decoration: none;' href='http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2' title='Lion takes a bite out of sports car'&gt;Lion takes a bite out of sports car&lt;/a&gt;&lt;/p&gt;</textarea>
            <select id="predefined-size">
              <option value="550x350">550x350</option>
              <option value="650x450">650x450</option>
              <option value="800x500">800x500</option>
            </select>
          </div>
        </div>
        <hr>
      </div><!-- /.share_conent -->
      <div class="video-description panel-body">
        <div class="row">
          <div class="col-sm-9">
            <p itemprop="description" class="this-description truncate">Lion
              takes a bite out of sports car</p>
          </div>
          <div class="col-sm-3">
            <p>
              <strong>Published</strong>
              10 months ago </p>
            <p>
              <strong>Category</strong>
              <a href="http://dailimeo.com/video" title="Video">Video</a>
              &nbsp;/&nbsp;
              <a href="http://dailimeo.com/channel/video/general" title="">General</a>
            </p>
            <p>
              <strong>Tags</strong><a
                href="http://dailimeo.com/search/Sports+Car+%28Automotive+Class%29"
                class="btn btn-info video-tag"><?php print vm_get_value($video, 'tag') ?></a>
              <a href="http://dailimeo.com/search/Lion+%28Animal%29"
                 class="btn btn-info video-tag">Lion (Animal)</a></p></div>
        </div>
      </div>
      <a style="display: none;" href="#" class="toggle-description">View
        More</a>
    </div><!-- /.video-option -->
  </div>
  <div class="panel panel-default" id="comments">
    <div class="panel-heading">Comments</div>
    <div class="row panel-body">
      <div class="col-sm-4 tabs">
        <a href="#comments_system"
           class="btn btn-block btn-primary">Comments</a>
      </div>
      <div class="col-sm-4 tabs">
        <a href="#comments_facebook"
           class="btn btn-block btn-facebook">Facebook</a>
      </div>
      <div class="col-sm-4 tabs">
        <a href="#comments_disqus" class="btn btn-block btn-success">Disqus</a>
      </div>
    </div>
    <div style="display: block;" class="panel panel-default tabbed"
         id="comments_system">
      <div class="panel-body">
        <form id="comment-form" method="post"
              action="http://dailimeo.com/server">
          <div class="return-data"></div>
          <div class="row">
            <div class="col-sm-1 hidden-xs hidden-sm">
              <img src="http://dailimeo.com/content/user/AgEgijgg_avatar.jpg"
                   alt="">
            </div>
            <div class="col-sm-11 col-xs-12">
              <textarea name="comment" class="form-control"
                        placeholder="Leave a comment here..."></textarea>
              <input name="action" value="comment" type="hidden">
              <input name="token" value="a1f967f04019c585634f92611eb9f3bb"
                     type="hidden">
              <input name="media" value="39" type="hidden">
              <input name="parentid" value="0" id="comment-parentid"
                     type="hidden">
              <span class="replyto"></span>
              <button type="submit" class="btn btn-primary pull-right">Submit
              </button>
            </div>
          </div>
        </form><!--/.comment-form-->
      </div>
      <div class="panel-body">
        <h2><span>0 Comments</span></h2>
        <ul class="media-list comments"></ul><!--/.comment-list --></div>
    </div>
    <div style="display: none;" class="panel-body tabbed"
         id="comments_facebook">
      <div class=" fb_reset" id="fb-root">
        <div
          style="position: absolute; top: -10000px; height: 0px; width: 0px;">
          <div>
            <iframe
              src="http://staticxx.facebook.com/connect/xd_arbiter/r/P5DLcu0KGJB.js?version=42#channel=f208e738f888eac&amp;origin=http%3A%2F%2Fdailimeo.com"
              style="border: medium none;" tabindex="-1"
              title="Facebook Cross Domain Communication Frame"
              aria-hidden="true" id="fb_xdm_frame_http" scrolling="no"
              allowfullscreen="true" allowtransparency="true"
              name="fb_xdm_frame_http" frameborder="0"></iframe>
            <iframe
              src="https://staticxx.facebook.com/connect/xd_arbiter/r/P5DLcu0KGJB.js?version=42#channel=f208e738f888eac&amp;origin=http%3A%2F%2Fdailimeo.com"
              style="border: medium none;" tabindex="-1"
              title="Facebook Cross Domain Communication Frame"
              aria-hidden="true" id="fb_xdm_frame_https" scrolling="no"
              allowfullscreen="true" allowtransparency="true"
              name="fb_xdm_frame_https" frameborder="0"></iframe>
          </div>
        </div>
        <div
          style="position: absolute; top: -10000px; height: 0px; width: 0px;">
          <div></div>
        </div>
      </div>
      <div fb-xfbml-state="rendered"
           class="fb-comments fb_iframe_widget fb_iframe_widget_fluid"
           data-href="http://dailimeo.com/view/lion-takes-a-bite-out-of-sports-car/MQgT2"
           data-num-posts="10" data-colorscheme="light" data-width="100%"><span
          style="height: 0px;"><iframe
            src="https://www.facebook.com/plugins/comments.php?api_key=&amp;channel_url=http%3A%2F%2Fstaticxx.facebook.com%2Fconnect%2Fxd_arbiter%2Fr%2FP5DLcu0KGJB.js%3Fversion%3D42%23cb%3Df1667eebf0832bc%26domain%3Ddailimeo.com%26origin%3Dhttp%253A%252F%252Fdailimeo.com%252Ff208e738f888eac%26relation%3Dparent.parent&amp;colorscheme=light&amp;href=http%3A%2F%2Fdailimeo.com%2Fview%2Flion-takes-a-bite-out-of-sports-car%2FMQgT2&amp;locale=en_US&amp;numposts=10&amp;sdk=joey&amp;skin=light&amp;width=100%25"
            class="fb_ltr fb_iframe_widget_lift" title="Facebook Social Plugin"
            style="border: medium none; overflow: hidden; height: 0px; width: 100%;"
            scrolling="no" name="ff5a2bf825acd4"
            id="fb37163ab23982"></iframe></span></div>
    </div>
    <script>(function (d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) return;
        js = d.createElement(s);
        js.id = id;
        js.src = "//connect.facebook.net/en_US/all.js#xfbml=1";
        fjs.parentNode.insertBefore(js, fjs);
      }(document, 'script', 'facebook-jssdk'));</script>
  </div>
</div>
