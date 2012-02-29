<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<h2>Signatures</h2>
<h3>See Why People Are Signing</h3>
<div class="tp-pet-signatures">
  <?php foreach ($rows as $count => $row): ?>
    <div class="tp-pet-signature-row">
      <div class="tp-pet-name">
        <?php print $row['first_name']; ?>
        <?php print $row['last_name']; ?>
        <br />
        <?php print $row['created']; ?>
      </div>
      <div class="tp-pet-comment"><?php print $row['comment']; ?></div>
    </div>
  <?php endforeach; ?>
</div>
