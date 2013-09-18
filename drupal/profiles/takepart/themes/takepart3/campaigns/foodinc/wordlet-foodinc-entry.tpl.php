<div class="content" id="foodinc-entryform">
  <h2><?=w('entry_form_title')?></h2>
  <section class="left-rail">
    <? foreach (wl('howto_section') as $ws): ?>
      <section>
        <h3><?= $ws->single ?><span><?= $ws->img_src ?></span></h3>
        <? if ($wis = wl($ws->token . '_items')): ?>
          <ul <?= wa($ws->token . '_items') ?>>
            <? foreach ($wis as $wi): ?>
              <li class="<?= $wi->single ?>"><?= $wi->multi ?></li>
            <? endforeach ?>
          </ul>
        <? endif ?>
      </section>
    <? endforeach ?>
  </section>
  <section class="entry-form-container right-rail">
    <?= w('entry_form') ?>
  </section>
</div>
