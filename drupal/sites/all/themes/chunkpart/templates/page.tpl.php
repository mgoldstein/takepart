<div id="skip-link" class="skip-link">
    <a href="#main"><?= t('Skip to main content') ?></a>
</div>

<header id="site-header" role="banner">
  <p id="site-logo">
    <img src="<?=$logo?>" alt="TakePart" role="logo" />
  </p>

  <nav id="site-nav">
    <div id="site-user-nav">
      <?=render($user_nav) ?>
    </div>

    <div id="site-main-nav">
      <?=render(menu_tree('main-menu')) ?>
    </div>

    <div id="site-search">
      <?=drupal_render(module_invoke('search_api_page', 'block_view', '2')) ?>
    </div>
  </nav>

  <div id="site-hot-nav">
    <?=render(menu_tree('menu-hot-topics')) ?>
  </div>

  <div id="site-miss-nav">
    <p><?=t('Don\'t Miss:') ?></p>
    <?=render(menu_tree('menu-don-t-miss')) ?>
  </div>

  <div id="site-participant-nav">
    <p>Participant Films</p>
    <?=render(menu_tree('menu-reel-impact')) ?>
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

<? // TODO: Confirm this block can be here with the site JS below it ?>
<?=render($page['footer']) ?>

<footer id="site-footer">
  <div class="inner">
    <? if ( ($nav = render(menu_tree('menu-takepart-topics'))) ): ?>
      <section id="site-topics">
        <h4><?=t('Topics') ?></h4>
        <?=$nav ?>
      </section>
    <? endif ?>

    <? if ( ($nav = render(menu_tree('menu-takepart-film-campaigns'))) ): ?>
      <section id="site-campaigns">
        <h4><?=t('Film Campaigns') ?></h4>
        <?=$nav ?>
        <p id="site-more-campaigns">
          <a href="/film-campaigns"><?=t('More Film Campaigns') ?></a>
        </p>
      </section>
    <? endif ?>

    <? if ( ($nav = render(menu_tree('menu-takepart-links'))) ): ?>
      <section id="site-takepart-links">
        <h4><?=t('About TakePart') ?></h4>
        <?=$nav ?>
      </section>
    <? endif ?>

    <section id="site-connect">
      <h4><?=t('Connect') ?></h4>
      <ul>
        <li class="fb"><a href="http://www.facebook.com/takepart" target="_blank" name="&lpos=footer">facebook</a></li>
        <li class="twitter"><a href="http://www.twitter.com/takepart" target="_blank" name="&lpos=footer">twitter</a></li>
        <li class="pinterest"><a href="http://pinterest.com/takepart/" target="_blank"><img src="http://passets-ec.pinterest.com/images/about/buttons/big-p-button.png" width="25" height="25" alt="Follow Me on Pinterest" /></a></li>
        <li class="googleplus"><a href="https://plus.google.com/113369936500827860065?prsrc=3" name="&lpos=footer" rel="publisher" style="text-decoration:none;" target="_blank" title="google plus"><img src="https://ssl.gstatic.com/images/icons/gplus-32.png" alt="google plus" style="border:0;width:24px;height:24px;" /></a></li>
        <li class="youtube"><a href="http://www.youtube.com/takepart" target="_blank" name="&lpos=footer">youtube</a></li>
        <li class="rss"><a href="/rss">rss</a></li>
      </ul>
    </section>
  </div>

  <section id="site-about">
    <p id="site-participant"><?=t('TakePart is the digital division of') ?> <a target="_blank" href="http://www.participantmedia.com/"><?=t('Participant Media') ?></a></p>
    <p id="site-copyright">&copy; 2008-<?=date('Y') ?> TakePart, LLC</p>
  </section>
</footer>