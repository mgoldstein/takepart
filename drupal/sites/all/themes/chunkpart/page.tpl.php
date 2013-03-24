<?=$logo?>

<? /*
<?php
  // Ignore the content added by the embeddable module, I have no idea what it
  // is for, it is probably admin stuff.
  unset($page['content']['embeddable']);
?>
<h1>Page Template Variables</h1>
<dl>
  <?php foreach(array_keys($variables) as $name): ?>
    <dt><?php print $name; ?></dt>
    <dd><pre><?php
      $repr = print_r($variables[$name], TRUE);
      print htmlentities($repr);
    ?></pre></dd>
  <?php endforeach; ?>
</dl>
<?php
  // The page regions provide buckets for Drupal to drop stuff in, we do not
  // need to continue using them in the markup, but they are how Drupal gets
  // information to the theme layer
?>
<h1>Page Regions</h1>
<ul>
  <?php foreach(array_keys($page) as $name): ?>
    <?php if (strncmp($name, '#', 1)): ?>
      <li><?php print $name; ?></li>
    <?php endif; ?>
  <?php endforeach; ?>
</ul>
*/ ?>
<?php
  // The article node is in the page's content region.
  // there are other regions
  print render($page['content']);
?>
