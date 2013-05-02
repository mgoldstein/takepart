<header id="site-header" role="banner"><div id="site-header-inner">
  <p id="site-logo">
    <a href="/"><img src="<?=($is_multipage)?'/profiles/takepart/themes/takepart3/images/logo-sm-slim.png':$logo?>" alt="TakePart" role="logo" /></a>
  </p>

  <div id="site-navs">
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
    <nav id="site-user-nav">
      <?=$user_nav ?>
    </nav>

    <nav id="site-follow">
      <ul>
        <li class="facebook"><a target="_blank" href="http://www.facebook.com/takepart">Facebook</a></li>
        <li class="twitter"><a target="_blank" href="http://www.twitter.com/takepart">Twitter</a></li>
        <li class="rss"><?php print l("rss", "node/19814", array('attributes' => array('title' => 'RSS'), 'absolute' => TRUE ) ); ?></li>
      </ul>
    </nav>

    <nav id="site-search">
      <?php print drupal_render($search_takepart_form); ?>
    </nav>

    <div id="site-participant-nav">
      <p>Participant Films</p>
      <?php print $participant_pulldown ?>
    </div>
  </div>
</div></header>