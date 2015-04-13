<figure class="row <?php print $alignment ? $alignment : ''; ?>">
  <?php print $img; ?>
  <?php if($caption): ?>
  <div class="caption col-xxs-12">
    <?php print $caption; ?>
  </div>
  <?php endif; ?>
</figure>