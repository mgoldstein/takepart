<div id="skip-link" class="skip-link">
    <a href="#main"><?= t('Skip to main content') ?></a>
</div>

<?=$header ?>

<main role="main" id="main">
 <aside id="site-top">
    <? foreach ( $page['content_top'] as $val ): ?>
      <? if ( ($block = _sblock($val)) ): ?>
        <? // TODO: get the section tag/classes onto blocks ?>
        <?=$block?>
      <? endif ?>
    <? endforeach ?>
  </aside>
  <?=render($page['content']) ?>

  <aside id="site-secondary">
    <? foreach ( $page['sidebar_second'] as $val ): ?>
      <? if ( ($block = _sblock($val)) ): ?>
        <? // TODO: get the section tag/classes onto blocks ?>
        <?=$block?>
      <? endif ?>
    <? endforeach ?>
  </aside>
</main>

<?=$footer ?>

<? // TODO: Confirm this block can be here with the site JS below it ?>
<?=render($page['footer']) ?>
