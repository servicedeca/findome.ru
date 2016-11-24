<?php foreach ($comments as $cid => $comment): ?>
  <div class="col-xs-12 comment-item">
    <label><?php print $comment['author'];?>
      <span>
        <?php if($comment['assessment'] == 1){print $good_finger;} elseif($comment['assessment'] == -1){ print $bad_finger;}?>
        <?php print $comment['date'];?>
      </span>
    </label>
    <p>
      <?php print $comment['comment']?>
    </p>

    <?php if (isset($comment['link_answer']) && !isset($comment['answer'])): ?>
      <a data-toggle="modal" data-target=".comment_modal" data-pid="<?php print $cid; ?>" id="answer_comment">Ответить</a>
    <?php endif; ?>

    <?php if (isset($comment['long']) && !isset($comment['answer'])): ?>
      <a data-toggle="modal" data-target=".comment_text" data-cid="<?php print $cid; ?>" id="get_data_comment">Читать далее...</a>
    <?php endif; ?>

    <?php if(isset($comment['answer'])): ?>
      <?php foreach($comment['answer'] as $a_cid => $answer): ?>
        <label><?php print $answer['author'];?><span><?php print $answer['date'];?></span></label>
        <p>
          <?php print $answer['comment']?>
        </p>
        <?php if (isset($answer['long'])): ?>
          <a data-toggle="modal" data-target=".comment_text" data-cid="<?php print $a_cid; ?>" id="get_data_comment">Читать далее...</a>
        <?php endif; ?>
      <?php endforeach;?>
    <?php endif;?>
  </div>

<?php endforeach; ?>