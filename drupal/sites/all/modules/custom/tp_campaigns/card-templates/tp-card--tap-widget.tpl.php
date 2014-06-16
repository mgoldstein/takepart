<div class="left <?php print implode(' ', $left_classes); ?>">
	<?php print $left; ?>
</div>
<?php if(!empty($right)): ?>
	<div class="right <?php print implode(' ', $right_classes); ?>">
		<?php print $right; ?>
	</div>
<?php endif; ?>