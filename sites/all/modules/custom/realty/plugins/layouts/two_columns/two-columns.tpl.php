<?php
/**
 * @file
 *
 * Template (admin) for the ob-glossary layout.
 */
?>

<div id="wrapper">
  <div class="container-fluid container-fix">

    <div class=" col-xs-2 navigation zero-padding">
      <?php if (!empty($content['content_left'])) : ?>
        <?php print $content['content_left']; ?>
      <?php endif; ?>
    </div>

    <div class="col-xs-10 col-xs-offset-2 table-block zero-padding">
      <?php if (!empty($content['content_right'])) : ?>
        <?php print $content['content_right']; ?>
      <?php endif; ?>
    </div>

  </div>
</div>