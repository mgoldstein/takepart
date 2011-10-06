(function ($) {
	Drupal.behaviors.boxFeature = { attach: function(context) {
		$('.block-boxes-features .featured_node:last').after('<a id="add_another_node_ref" href="#">Add another field</a>');

		$('a#add_another_node_ref').click(function(event) {
			event.preventDefault();
			var first_hidden = $('.featured_node.hidden:first');
			var new_weight = $('.featured_node:not(.hidden)').size();
			first_hidden.find('.featured-node-weight').attr('value', new_weight);
			first_hidden.removeClass('hidden');
			if ($('.featured_node.hidden').length == 0) {
				$('a#add_another_node_ref').hide();
			}
		});
		
		$("#sortable").sortable({
			stop: function(event, ui) {
				var count = 0;
				$('.featured_node:not(.hidden)').each(function(i) {
					$(this).find('input.featured-node').attr('name', 'featured_node_' + count);
					$(this).find('input.featured-node-weight').attr('name', 'featured_node_weight_' + count);
					$(this).find('.featured-node-weight').attr('value', count);
					count++;
				});
			}
		});
		
	}};
})(jQuery);