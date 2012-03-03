<?php
/**
 * @file views-view-list.tpl.php
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php print $list_type_prefix; ?>
  <?php //3 columns:
        $percol = (int) ((count($rows)+1) / 3); 
        $counter = 0;
        $col = 0; ?>
    <div class="col col-0">
    <?php foreach ($rows as $id => $row): ?>
        <li class="<?php print $classes_array[$id]; ?> row-<?php print ($counter % $percol); ?>">
        <?php print $row; ?>
        </li> 
        <?php if ((($counter % $percol)==0) && ($counter != $percol-1) && ($counter != 0)): $col++; ?></div><div class="col col-<?php print $col; ?>"><?php endif; ?>
        <?php $counter++; ?>
    <?php endforeach; ?>
    </div>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>
