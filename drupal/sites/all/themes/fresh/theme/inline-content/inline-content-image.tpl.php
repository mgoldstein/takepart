<figure class="row <?php print $alignment ? $alignment : ''; ?>">
  <div class="inline-feature-image">
  <?php print $img; ?>
  <?php if($caption): ?>
  <div class="caption col-xxs-12">
    <?php print $caption; ?>
  </div>
  <?php endif; ?>
  </div>
</figure>