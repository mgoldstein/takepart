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

<article id="article-main">
	<header id="article-header">
		<h1 id="article-headline"><?=_s($title) ?></h1>
		<p id="article-abstract"><?=_s($field_article_subhead) ?></p>
		<p id="article-badge">{Article Badge}</p>
		<p id="article-date"><?=$date?><? //=date('F j, Y', )?></p>
		<p id="article-author-name"><a href="{Author link}"><?=$author?></a></p>
	</header>

	<div id="article-sidebar">
		<aside id="article-social" class="social">
			<p>{Take Action Button}</p>
			<div class="tp-social" id="article-share"></div>
			<p id="article-comments-link" class="comments-link">
				<a href="#article-comments"><?=t('Comments') ?><span class="count"></span></a>
			</p>
		</aside>

		<aside id="article-author">
			<? if ( $author = _snode($field_author) ): ?>
				<?=_simage($author->field_profile_photo->value())?>
				<h3><?=$author->title->value() ?></h3>
				<? if ( $abody = $author->body->value() ): ?>
					<div class="body">
						<?=$abody['summary'] ?>
						<a href="#">{Full Bio}</a>
					</div>
				<? endif ?>
				{Follow me}
			<? endif ?>
		</aside>
	</div>

	<div id="article-content">
		<div id="article-body">
			<?=_simage($field_article_main_image)?>
			<?=_s($body)?>
		</div>

		<footer id="article-footer">
			<nav id="next-article">
				<p><?=t('Next Article') ?></p>
				<p><a href="#">{Next Article}</a></p>
			</nav>
		</footer>

		<section id="article-comments" class="comments">
			<h3><?=t('Comments') ?> <span class="count"></span></h3>
			{Comments module}
		</section>

<pre>
-----------------
<? var_dump(array_keys(get_defined_vars())) ?>

-----------------
<? //_l($w) ?>
-----------------
</pre>
	</div>
</article>