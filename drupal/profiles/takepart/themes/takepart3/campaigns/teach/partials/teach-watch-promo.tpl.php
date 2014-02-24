<section class="teach-watch-promo">
  <div class="teach-watch-promo-content">
    <h2 class="sect-headline"><?=w('teach-promo-header')?></h2>
    <ul <?=wa('teach-promo-links')?>>
      <? foreach( wl('teach-promo-links') as $w ): ?>
      <li>
        <a href="<?=$w->href?>">
          <img class="media-logo" src="<?=$w->img_src?>" alt="<?=$w->token?>" />
          <span><?=$w->single(false)?></span>
        </a>
      </li>
      <? endforeach; ?>
    </ul>
  </div>
</section>