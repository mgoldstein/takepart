<div id="skip-link" class="skip-link">
    <a href="#main"><?= t('Skip to main content') ?></a>
</div>

<header id="site-header" role="banner">
  <nav id="site-user-nav">
    <?=$user_nav ?>
  </nav>

  <p id="site-logo">
    <a href="/"><img src="<?=$logo?>" alt="TakePart" role="logo" /></a>
  </p>

  <div id="site-navs">
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
</header>

<? /*
<?php
  // Ignore the content added by the embeddable module, I have no idea what it
  // is for, it is probably admin stuff.
  unset($page['content']['embeddable']);
?>
<h1>Page Template Variables</h1>
<dl>
  <?php foreach(array_keys($variables) as $name): ?>
    <dt><?php print $name; ?></dt>
    <dd><pre><?php
      $repr = print_r($variables[$name], TRUE);
      print htmlentities($repr);
    ?></pre></dd>
  <?php endforeach; ?>
</dl>
<?php
  // The page regions provide buckets for Drupal to drop stuff in, we do not
  // need to continue using them in the markup, but they are how Drupal gets
  // information to the theme layer
?>
<h1>Page Regions</h1>
<ul>
  <?php foreach(array_keys($page) as $name): ?>
    <?php if (strncmp($name, '#', 1)): ?>
      <li><?php print $name; ?></li>
    <?php endif; ?>
  <?php endforeach; ?>
</ul>
*/ ?>

<main role="main" id="main">
  <?=render($page['content']) ?>

  <aside id="site-secondary">
    <? foreach ( $page['sidebar_second'] as $val ): ?>
      <? if ( ($block = _sblock($val)) ): ?>
        <? // TODO: get the section tag/classes onto blocks ?>
        <section>
          <?=$block?>
        </section>
      <? endif ?>
    <? endforeach ?>
  </aside>
</main>

<footer id="site-footer">
  <div class="inner">
    <? if ( ($nav = _smenu('menu-takepart-topics')) ): ?>
      <section id="site-topics">
        <h4><?=t('Topics') ?></h4>
        <?=$nav ?>
      </section>
    <? endif ?>

    <? if ( ($nav = _smenu('menu-takepart-film-campaigns')) ): ?>
      <section id="site-campaigns">
        <h4><?=t('Film Campaigns') ?></h4>
        <?=$nav ?>
        <p id="site-more-campaigns">
          <a href="/film-campaigns"><?=t('More Film Campaigns') ?></a>
        </p>
      </section>
    <? endif ?>

    <? if ( ($nav = _smenu('menu-takepart-links')) ): ?>
      <section id="site-takepart-links">
        <h4><?=t('About TakePart') ?></h4>
        <?=$nav ?>
      </section>
    <? endif ?>

    <section id="site-connect">
      <h4><?=t('Connect') ?></h4>
      <ul>
        <li class="facebook"><a href="http://www.facebook.com/takepart">Facebook</a></li>
        <li class="twitter"><a href="http://www.twitter.com/takepart">Twitter</a></li>
        <li class="google"><a href="https://plus.google.com/113369936500827860065?prsrc=3">Google+</a></li>
        <li class="pinterest"><a href="http://pinterest.com/takepart/">Pinterest</a></li>
        <li class="youtube"><a href="http://www.youtube.com/takepart">YouTube</a></li>
        <li class="tumblr"><a href="#">YouTube</a></li>

        <!-- li class="rss"><a href="/rss">RSS</a></li -->
      </ul>
    </section>
  </div>

  <section id="site-about">
    <p id="site-participant"><?=t('TakePart is the digital division of') ?> <a target="_blank" href="http://www.participantmedia.com/"><?=t('Participant Media') ?></a></p>
    <p id="site-copyright">&copy; 2008-<?=date('Y') ?> TakePart, LLC</p>
  </section>
</footer>

<? // TODO: Confirm this block can be here with the site JS below it ?>
<?=render($page['footer']) ?>
