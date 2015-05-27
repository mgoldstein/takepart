<div class="author-teaser col-xxs-12 col-xs-10 col-xs-offset-1">
  <div class="line line-style-2"></div>
<?php foreach($variables['authors'] as $author): ?>
  <div class="row author">
    <div class="image col-xxs-2"><img class="img-circle" src="<?php print $author['image']; ?>" /></div>
    <?php if(!empty($variables['date'])): ?>
      <div class="published-at col-xxs-10"><?php print $variables['date']; ?></div>
    <?php endif; ?>
    <div class="about col-xxs-10 col-xs-6"><?php print $author['about']; ?></div>
    <div class="links col-xxs-10 col-xxs-offset-2 col-xs-4 col-xs-offset-0">
      <ul class="menu horizontal-menu">
        <?php foreach($author['links'] as $link): ?>
          <li><?php print $link; ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
<?php 
	unset($variables['date']);
	endforeach;
?>
  <div class="line line-style-1"></div>
</div>