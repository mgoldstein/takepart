<?php if ($is_multipage): ?>
  <div id="slim-header" class='clearfix multipage-campaign'>
    <div id="logo"><?php print l("", "<front>", array('attributes' => array('title' => 'TakePart logo'), 'absolute' => TRUE ) ); ?></div>
    <div class="clear clearfix" id="nav-wrap">
      <?php print $top_nav ?> 
    </div>
    <div id="top-search">
      <div class="tpform-item"><?php print drupal_render($search_takepart_form); ?></div>
    </div><!--/top search-->
    <div id="join-login-top">
      <div class="login-fb clearfix">
        <?php print $user_nav; ?>       
      </div> 
    </div><!--/join-login-top-->
    <?php print $follow_us_links; ?><!--/top follow-->
  </div>
<?php else: ?>
  <div id="header-wrapper" class='clearfix regular-content'>
  	<div id="join-login-top">
    	<div class="login-fb clearfix">
      	<?php print $user_nav; ?>       
      </div> 
    </div><!--/join-login-top-->
    <?php print $follow_us_links; ?><!--/top follow-->
    <div class="logo-wrapper">
  		<div id="logo"><?php print l("", "<front>", array('attributes' => array('title' => 'TakePart logo', 'absolute' => TRUE) ) )?></div>
			<div class="header-right">
        <div id="nav-wrap" class="clear clearfix">
          <div id="block-menu-block-1">
            <?php print $top_nav ?>
          </div>
        </div>
        <div id="participant-pulldown">
        </div>
        <div class="row2">
          <div id="hot-topics-nav">
            <?php print $hottopic_nav ?>
          </div><!--/hot topics nav-->
          <div id="top-search">
            <div class="tpform-item"><?php print drupal_render($search_takepart_form); ?></div>
          </div><!--/top search-->
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>  