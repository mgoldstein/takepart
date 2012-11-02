<?php
/*
 * This is the template for the action embed not that we are NOT RENDERING
 * THE CONTENT OF THE DISPLAY MODE SETTING.  This is an isolated case
 * of just action embeds so it might not be a problem.
 *
 * We are going to leave the embed display mode empty so it is
 * clear that we are not using those settings
 */
$graphic_link = l(t('<span>Take Action!</span>'), "node/{$node->nid}", array('html' => TRUE));
$title_link = l($node->title, "node/{$node->nid}");
?>
<div class="embedaction-wrapper link clearfix">
  <div class="more-actions">
  <a class="button takepart-custom-take-action-button" href="javascript:void()"><span>See More Actions</span></a></div>
  <div class="header">
  <table>
  <tbody>
  <tr>
  <td class="graphic"><?php print $graphic_link; ?></td>
  <td class="title"><?php print $title_link; ?></td>
  </tr>
  </tbody>
  </table>
  </div>
</div>
