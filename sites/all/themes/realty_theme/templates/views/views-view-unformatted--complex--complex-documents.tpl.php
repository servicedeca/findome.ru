<?php if(isset($documents)):?>
  <?php foreach($documents as $document):?>

    <div class="col-xs-12 zero-padding doc-item">
      <div class="col-xs-1 doc-icon zero-padding">
        <?php print $image?>
      </div>
      <div class="col-xs-11 col-xs-ofset-1 doc-download">
        <p><?php print $document['title']?></p>
        <?php print $document['link_download']?>
      </div>
    </div>

  <?php endforeach;?>
<?php endif?>