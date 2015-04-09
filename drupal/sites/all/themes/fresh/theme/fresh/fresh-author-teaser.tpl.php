<div class="author-teaser col-xxs-12">
  <div class="line line-style-2"></div>
  <div class="row">
    <?php if(!empty($variables['date'])): ?>
      <div class="published-at col-xxs-10 col-xxs-offset-2"><?php print $variables['date']; ?></div>
    <?php endif; ?>
    <div class="image col-xxs-2"><img class="img-circle" src="<?php print $variables['image']; ?>" /></div>
    <div class="about col-xxs-10"><?php print $variables['about']; ?></div>
  </div>

  <div class="row">
    <div class="links col-xxs-10 col-xxs-offset-2">
      <ul class="menu horizontal-menu">
        <?php foreach($variables['links'] as $link): ?>
          <li><?php print $link; ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
  <div class="line line-style-1"></div>
</div>