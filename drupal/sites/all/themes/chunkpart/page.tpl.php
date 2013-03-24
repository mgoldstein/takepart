<div id="skip-link" class="skip-link">
    <a href="#main"><?= t('Skip to main content') ?></a>
</div>

<header id="site-header">
  <p id="logo">
    <img src="<?=$logo?>" alt="TakePart logo" />
  </p>

  <nav id="user-nav">
    <?=render($user_nav) ?>
  </nav>

  <nav id="main-menu-nav">
    <?=render(menu_tree('main-menu')) ?>
  </nav>

  <nav id="menu-reel-impact-nav">
    <?=render(menu_tree('menu-reel-impact')) ?>
  </nav>

  <nav id="menu-hot-topics-nav">
    <?=render(menu_tree('menu-hot-topics')) ?>
  </nav>

  <nav id="menu-don-t-miss-nav">
    <p><?=t('Don\'t Miss:') ?></p>
    <?=render(menu_tree('menu-don-t-miss')) ?>
  </nav>

  <?=drupal_render(module_invoke('search_api_page', 'block_view', '2')) ?>
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

<? var_dump(($variables))?>

  <? foreach ( $page['sidebar_second'] as $block ): ?>
    <?=render($block)?>
  <? endforeach ?>
</main>

<footer id="site-footer">
  <?=render($page['footer']) ?>
  
  <? if ( ($nav = render(menu_tree('menu-takepart-topics'))) ): ?>
    <div>
      <p class="column-title">Topics</p>
      <?=$nav ?>
    </div>
  <? endif ?>

  <? if ( ($nav = render(menu_tree('menu-takepart-film-campaigns'))) ): ?>
    <div>
      <?=$nav ?>
      
      <p>
        <a href="/film-campaigns">More Film Campaigns</a>
      </p>
    </div>
  <? endif ?>

  <? if ( ($nav = render(menu_tree('menu-takepart-links'))) ): ?>
    <div>
      <p>About TakePart</p>

      <?=$nav ?>
    </div>
  <? endif ?>

  <div id="footer-links-share" class="footer-column-wrapper">
    <p>Connect</p>
    <ul id="bottom-follow">
      <li class="fb"><a href="http://www.facebook.com/takepart" target="_blank" name="&lpos=footer">facebook</a></li>
      <li class="twitter"><a href="http://www.twitter.com/takepart" target="_blank" name="&lpos=footer">twitter</a></li>
      <li class="pinterest"><a href="http://pinterest.com/takepart/" target="_blank"><img src="http://passets-ec.pinterest.com/images/about/buttons/big-p-button.png" width="25" height="25" alt="Follow Me on Pinterest" /></a></li>
      <li class="googleplus"><a href="https://plus.google.com/113369936500827860065?prsrc=3" name="&lpos=footer" rel="publisher" style="text-decoration:none;" target="_blank" title="google plus"><img src="https://ssl.gstatic.com/images/icons/gplus-32.png" alt="google plus" style="border:0;width:24px;height:24px;" /></a></li>
      <li class="youtube"><a href="http://www.youtube.com/takepart" target="_blank" name="&lpos=footer">youtube</a></li>
      <li class="rss"><a href="/rss">rss</a></li>
    </ul>
    
    <div id="footer-about">
      <p>TakePart is the digital division of <a target="_blank" href="http://www.participantmedia.com/">Participant Media</a></p>
      <div id="footer-legal">
        &copy; 2008-<?=date('Y') ?>
        TakePart, LLC
      </div>
    </div>
  </div>
</footer>