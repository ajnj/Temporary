<ul id="custom-tweaks-languages-menu" class="main-menu links inline">
  <li>
    <a href="#">Languages</a>
    <ul>
      <?php foreach ($items as $lang => $label): ?>
        <li><a href="https://translate.google.com/translate?u=<?php print $url; ?>&langpair=en%7C<?php print $lang; ?>&hl=en&ie=UTF-8&oe=UTF-8">English to <?php print $label; ?></a></li>
      <?php endforeach; ?>
    </ul>
  </li>
</ul>
<script>
  // If we are in iframe, then do not render languages menu, as we are assuming
  // that's Google Translate iframe.
  function inIframe() {
      try {
          return window.self !== window.top;
      } catch (e) {
          return true;
      }
  }

  if (inIframe()) {
    var element = document.getElementById("custom-tweaks-languages-menu");
    element.classList.add("element-invisible");
  }
</script>
