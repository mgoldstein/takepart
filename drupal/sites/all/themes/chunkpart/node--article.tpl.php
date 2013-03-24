<style>
.data { white-space: nowrap; }
</style>
<? /*
<h1>Article Node Template Variables</h1>
<dl>
  <?php foreach(array_keys($variables) as $name): ?>
    <dt><?php print $name; ?></dt>
    <dd><pre><?php
      $repr = print_r($variables[$name], TRUE);
      print htmlentities($repr);
    ?></pre></dd>
  <?php endforeach; ?>
</dl>
* /
?>
<pre>
<?=drupal_realpath('public://profiles/photos/AbbySchanfield.jpg');?>

<?=theme('image', $variables)?>
<? 
	var_dump(array_keys($variables));
	var_dump($node);
?>
</pre>

<?=render(field_view_field('node', $node, 'body')); ?>
 

<?*/

?>

<h1><?=_s($title) ?></h1>
<p class="abstract"><?=_s($field_article_subhead) ?></p>
<div class="body"><?=_s($body)?></div>

<pre>
-----------------
<? var_dump(array_keys(get_defined_vars()))?>
-----------------
</pre>

<? // listArrayRecursive(&$node, '$node'); ?>

