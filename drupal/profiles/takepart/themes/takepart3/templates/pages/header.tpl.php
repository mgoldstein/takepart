<header id="site-header" role="banner"><div id="site-header-inner">
  <p id="site-logo">
    <a href="/"><img src="<?=$logo?>" alt="TakePart" role="logo" /></a>
  </p>

  <div id="site-navs">
    <nav id="site-user-nav">
      <?=$user_nav ?>
    </nav>

    <nav id="site-main-nav">
      <?php print $top_nav ?>
    </nav>

    <div id="site-hot-nav">
      <?php print $hottopic_nav ?>
    </div>

    <div id="site-miss-nav">
      <p><?=t('Don\'t Miss:') ?></p>
      <?php print $dontmiss_nav ?>
    </div>
  </div>

  <div id="site-more-navs">
    <nav id="site-search">
      <?php print drupal_render($search_takepart_form); ?>
    </nav>

    <div id="site-participant-nav">
      <p>Participant Films</p>
      <?php print $participant_pulldown ?>
    </div>
  </div>
</div></header>


<!-- div id="header-wrapper" class="clearfix regular-content <?=($is_multipage)?'slim-header':''?>">
	<div id="join-login-top">
  	<div class="login-fb clearfix">
    	<?php print $user_nav; ?>       
    </div> 
  </div><!--/join-login-top- ->
  <?php print $follow_us_links; ?><!--/top follow- ->
  <div class="logo-wrapper">
		<div id="logo"><?php print l("Home", "<front>", array('attributes' => array('title' => 'TakePart logo', 'absolute' => TRUE) ) )?></div>
		<div class="header-right">
      <div id="nav-wrap" class="clear clearfix">
        <div id="block-menu-block-1">
          <?php print $top_nav ?>
        </div>
      </div>
      <div id="participant-pulldown">
        <div class="pp-button"></div>
        <div class="inner">
          <?php print $participant_pulldown ?>
        </div>
      </div>
      <div class="row2 clear clearfix">
        <div id="hot-topics-nav">
          <?php print $hottopic_nav ?>
        </div><!--/hot topics nav- ->
        <div id="dontmiss-nav">
          <div class="dont">Don't Miss:</div>
          <?php print $dontmiss_nav ?>
        </div><!--/hot topics nav- ->
        <div id="top-search">
          <div class="tpform-item"><?php print drupal_render($search_takepart_form); ?></div>
        </div><!--/top search- ->
      </div>
    </div>
  </div>
</div -->