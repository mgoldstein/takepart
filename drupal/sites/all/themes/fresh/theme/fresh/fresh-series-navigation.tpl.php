<div class="series-navigation">
  <?php if($variables['topic_box']): ?>
    <?php print $variables['topic_box']; ?>
  <?php endif; ?>
  <div class="navigation">
    <div class="item item-left text-left">
    <?php if($variables['prev_title']): ?>
      <a href="<?php print $variables['prev_link']; ?>">
        <div class="label">
          <span class="icon i-double-arrow-left"></span>Previous
        </div>
        <h4 class="series-nav-title">
          <?php print $variables['prev_title']; ?>
        </h4>
      </a>
    <?php endif; ?>
      </div>
    <div class="item item-right text-right">
    <?php if($variables['next_title']): ?>
      <a href="<?php print $variables['next_link']; ?>">
        <div class="label">
          Next<span class="icon i-double-arrow-right">
        </div>
        <h4 class="series-nav-title">
          <?php print $variables['next_title']; ?>
        </h4>
      </a>
    <?php endif; ?>
    </div>
  </div>
</div>