<div class="series-navigation">
  <?php if($variables['topic_box']): ?>
    <?php print $variables['topic_box']; ?>
  <?php endif; ?>
  <div class="navigation">
    <?php if($variables['prev_title']): ?>

        <a class="item item-left text-left" href="<?php print $variables['prev_link']; ?>">
          <div class="label">
            <span class="icon i-double-arrow-left>"></span><div class="series-nav-link">Previous</div>
          </div>
          <h4 class="series-nav-title">
            <?php print $variables['prev_title']; ?>
          </h4>
        </a>

    <?php endif; ?>
    <?php if($variables['next_title']): ?>

        <a class="item item-right text-right" href="<?php print $variables['next_link']; ?>">
          <div class="label">
            </span><div class="series-nav-link">Next</div><span class="icon i-double-arrow-right>">
          </div>
          <h4 class="series-nav-title">
            <?php print $variables['next_title']; ?>
          </h4>
        </a>

    <?php endif; ?>
  </div>
</div>