  <div id="slim-header" class='clearfix multipage-campaign'>
    <div id="logo"><?php print l("", "<front>", array('attributes' => array('title' => 'TakePart logo'), 'absolute' => TRUE ) ); ?></div>
    <div class="clear clearfix" id="nav-wrap">
      <?php print $top_nav ?> 
    </div>
    <div id="topnav-right">
      <div id="join-login-top">
        <div class="login-fb clearfix">
          <?php print $user_nav; ?>
        </div>
      </div><!--/join-login-top-->
      <div id="top-search">
        <div class="tpform-item"><?php print drupal_render($search_takepart_form); ?></div>
      </div><!--/top search-->
        <?php print $follow_us_links; ?><!--/top follow-->
    </div>
  </div>