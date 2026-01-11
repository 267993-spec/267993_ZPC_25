/* Simple lightbox for images in <main> */
(function(){
  function createLightbox(){
    var overlay = document.createElement('div');
    overlay.className = 'lb-overlay';

    var img = document.createElement('img');
    img.className = 'lb-img';
    overlay.appendChild(img);

    var close = document.createElement('button');
    close.className = 'lb-close';
    close.type = 'button';
    close.innerHTML = '✕';

    document.body.appendChild(overlay);
    document.body.appendChild(close);

    function show(src){
      img.src = src;
      overlay.classList.add('visible');
      close.classList.add('visible');
      document.body.style.overflow = 'hidden';
    }
    function hide(){
      overlay.classList.remove('visible');
      close.classList.remove('visible');
      document.body.style.overflow = '';
    }

    overlay.addEventListener('click', function(e){
      if(e.target === overlay) hide();
    });
    close.addEventListener('click', hide);
    document.addEventListener('keydown', function(e){ if(e.key === 'Escape') hide(); });

    return { show: show, hide: hide };
  }

  document.addEventListener('DOMContentLoaded', function(){
    var lb = createLightbox();
    var imgs = document.querySelectorAll('main img');
    imgs.forEach(function(i){
      i.style.cursor = 'zoom-in';
      i.addEventListener('click', function(){
        var src = i.getAttribute('data-large') || i.src;
        lb.show(src);
      });
    });
  });
})();
