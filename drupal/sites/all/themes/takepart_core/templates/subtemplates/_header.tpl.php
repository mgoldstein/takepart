<header id="site-header" role="banner"><div id="site-header-inner">
  <p id="site-logo">
    <a href="/"><img src="<?=$logo?>" alt="TakePart" role="logo" /></a>
  </p>

  <div id="site-navs">
    <nav id="site-user-nav">
      <?=$user_nav ?>
    </nav>

    <nav id="site-main-nav">
      <?=_smenu('main-menu') ?>
    </nav>

    <div id="site-hot-nav">
      <?=_smenu('menu-hot-topics') ?>
    </div>

    <div id="site-miss-nav">
      <p><?=t('Don\'t Miss:') ?></p>
      <?=_smenu('menu-don-t-miss') ?>
    </div>
  </div>

  <div id="site-more-navs">
    <nav id="site-search">
      <?=drupal_render(module_invoke('search_api_page', 'block_view', '2')) ?>
    </nav>

    <div id="site-participant-nav">
      <p>Participant Films</p>
      <?=_smenu('menu-reel-impact') ?>
    </div>
  </div>
</div></header>