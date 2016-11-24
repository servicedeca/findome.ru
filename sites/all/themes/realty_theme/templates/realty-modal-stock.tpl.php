<div class="container container-modal-stock zero-padding">
  <div class="col-xs-12 header-container-modal-stock header-block">
    <div class="vertical">
      <h2><?php print $node->title; ?></h2>
    </div>
    <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
      <?php print $img_close; ?>
    </button>
  </div>
  <div class="col-xs-12 list-modal-stock zero-padding">
    <?php print $image; ?>
    <?php if(!empty($node->body)): ?>
      <?php print $node->body[LANGUAGE_NONE][0]['safe_value'];?>
    <?php else: ?>
      <?php print $node->field_mini_description[LANGUAGE_NONE][0]['safe_value']; ?>
    <?php endif; ?>
  </div>
</div>
