<table>
	<tr>
		<th>Name</th>
		<th class="old">keys_data</th>
		<th class="old">items_data</th>
		<th class="new">configs</th>
		<th class="new">values</th>
	</tr>
<?

$res = db_select('wordlet', 'w')
    ->fields('w')
    //->condition('w.name', 'snap_slides')
    ->execute();

while ($row = $res->fetchAssoc()) {
 	$keys_data = $row['keys_data'];
 	$items_data = $row['items_data'];

 	if ( !$keys_data ) {
 		$configs = '';
 		$values = '';
 	} else {
 		$keys_data = explode(',', $keys_data);
 		$items_data = unserialize($items_data);

 		$configs = array();
 		$values = array();

 		foreach ( $keys_data as $k => $name ) {
 			$multi = 0;
 			$wordlet = 0;
 			$texts = array();
 			//$value = $items_data[$k];

 			switch ($name) {
 				case 'multi':
 					$multi = 1;
 					break;
 				case 'single':
 					$wordlet = 1;
 					break;
 				case 'href':
 				case 'img_src':
 				case 'thumb_src':
 					break;
 				//case 'nid',
 				//case 'node',
 				//case 'view_mode',
 				case 'form':
 					//$value = unserialize($value);
 					break;
 			}

 			$configs[] = array(
 				'name' => $name,
 				'title' => $name,
 				'default' => '',
 				'description' => '',
 				'format' => $row['format'],
 				'multi' => $multi,
 				'wordlet' => $wordlet,
 			);
 		}

 		foreach ( $items_data as $k => $v ) {
 			$texts = array();

 			foreach ( $configs as $config ) {
	 			$texts[$config['name']] = $v[$config['name']];
 			}
 			$values[] = $texts;
 		}

 	}

 	$wordlet = array(
 		'id' => $row['id'],
 		'page' => $row['page'],
 		'name' => $row['name'],
 		'title' => $row['title'],
 		'description' => $row['description'],
 		'cardinality' => $row['cardinality'],
 		'weight' => $row['weight'],
 		'created' => $row['created'],
 		'changed' => $row['changed'],
 		'status' => $row['status'],
 		'module' => $row['module'],

 		'configs' => $configs,
 		'values' => $values,
 	);

 	?>
 	<tr>
 		<td><?=$row['page']?>:<?=$row['name']?></td>
 		<td class="old"><pre><?=htmlspecialchars(print_r($keys_data, true)) ?></pre></td>
 		<td class="old"><pre><?=htmlspecialchars(print_r($items_data, true)) ?></pre></td>
 		<?php /* <!-- td><textarea><?php var_dump($wordlet) ?></textarea></td -->*/ ?>
 		<td class="new"><pre><?=htmlspecialchars(print_r($configs, true)) ?></pre></td>
 		<td class="new"><pre><?=htmlspecialchars(print_r($values, true)) ?></pre></td>
 	</tr>
 	<?
}

?></table>

<style>
textarea {
	width: 100%;
	height: 100%;
}

.new {
	background: #dfd;
}

.old {
	background: #fdd;
}

th,
td {
	vertical-align: top;
	border: 1px solid #000;
	border-left: none;
	border-top: none;
}

table {
	border-left: 1px solid #000;
	border-top: 1px solid #000;
}

pre {
	max-width: 300px;
	overflow: auto;
}
</style>