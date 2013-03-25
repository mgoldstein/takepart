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

<article>
	<header>
		<h1><?=_s($title) ?></h1>
		<p class="abstract"><?=_s($field_article_subhead) ?></p>
		<p class="date"><?=$date?><? //=date('F j, Y', )?></p>
		<p class="author"><a href="#"><?=$author?></a></p>
	</header>

	<div id="article-sidebar">
		<aside id="article-social" class="social">
			<p>tab</p>
			<div class="social-links"></div>
			<p id="article-comments-link" class="comments-link">
				<a href="#article-comments"><span class="count">Comments</span></a>
			</p>
		</aside>

		<aside id="article-author">
			<?=_simage($field_author->field_profile_photo)?>
			<h3><?=_s($field_author->title)?></h3>
			<div class="body">
				<?=_simage($field_article_main_image)?>
				<?=_s($author->body)?>
			</div>
		</aside>
	</div>

	<div id="article-body">
		<?=_s($body)?>
	</div>

	<footer id="article-footer">
		<nav id="next-article">
			<p><?=t('Next Article') ?></p>
			<p><a href="#">Next Article Title</a></p>
		</nav>
	</footer>

	<section id="article-comments" class="comments">
		<h3><?=t('Comments') ?> <span class="count"></span></h3>
	</section>

	<pre>
	-----------------
	<? var_dump(array_keys(get_defined_vars())) ?>
	<? var_dump($field_article_main_image) ?>
	<? _l($field_article_main_image) ?>
	-----------------
	</pre>

	<? // listArrayRecursive(&$node, '$node'); ?>
</article>