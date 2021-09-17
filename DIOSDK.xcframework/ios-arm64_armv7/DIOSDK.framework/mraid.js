(function() {
  var mraid = window.mraid = {};
  var mraidData = window.mraidData = {};

  //////////////////////////////////////////////////////////////////////////////////////////////////
 
  window.mraidBridge = {};

  window.mraidBridge.setSupportProperties = function(supportProperties) {
    mraidData.supportProperties = supportProperties;
  }

  window.mraidBridge.setExpandProperties = function(width, height, useCustomClose, isModal) {
    mraidData.expandProperties = {
      width: width,
      height: height,
      useCustomClose: useCustomClose,
      isModal: isModal
    };
  };

  window.mraidBridge.setMaxSize = function(width, height) {
    mraidData.maxSize = {
      width: width,
      height: height
    };
  };

  window.mraidBridge.setScreenSize = function(width, height) {
    mraidData.screenSize = {
      width: width,
      height: height
    };
  };

  window.mraidBridge.setCurrentPosition = function(x, y, width, height) {
    mraidData.currentPosition = {
      x: x,
      y: y,
      width: width,
      height: height
    };
  };

  window.mraidBridge.setDefaultPosition = function(x, y, width, height) {
    mraidData.defaultPosition = {
      x: x,
      y: y,
      width: width,
      height: height
    };
  };

  window.mraidBridge.setCurrentAppOrientation = function(orientation, locked) {
    mraidData.currentAppOrientation = {
      orientation: orientation,
      locked: locked
    };
  };

  window.mraidBridge.setOrientationProperties = function(allowOrientationChange, forceOrientation) {
    mraidData.orientationProperties = {
      allowOrientationChange: allowOrientationChange,
      forceOrientation: forceOrientation
    };
  };

  window.mraidBridge.triggerEvent = function (ev, params) {
    if (mraid.evListeners.hasOwnProperty(ev)) {
      for (var i = 0; i < mraid.evListeners[ev].length; i++) {
        mraid.evListeners[ev][i].apply(null, params);
      }
    }
  };

  //////////////////////////////////////////////////////////////////////////////////////////////////

  mraid.VERSION = '3.0';

  mraid.STATES = {
    LOADING: 'loading',
    DEFAULT: 'default',
    EXPANDED: 'expanded',
    HIDDEN: 'hidden',
    RESIZED: 'resized'
  };

  mraid.EVENTS = {
    ERROR: 'error',
    INFO: 'info',
    READY: 'ready',
    STATECHANGE: 'stateChange',
    VIEWABLECHANGE: 'viewableChange',
    SIZECHANGE: 'sizeChange'
  };

  mraid.PLACEMENT_TYPES = {
    UNKNOWN: 'unknown',
    INLINE: 'inline',
    INTERSTITIAL: 'interstitial'
  };

  //////////////////////////////////////////////////////////////////////////////////////////////////

  mraid.evListeners = {};
  window.mraidData.state = mraid.STATES.LOADING;

  mraid.getVersion = function() {
    return mraid.VERSION;
  }

  mraid.isViewable = function() {
    return window.mraidData.isViewable;
  }

  mraid.supports = function(feature) {
    return window.mraidData.supportProperties[feature];
  };

  mraid.getExpandProperties = function() {
    return window.mraidData.expandProperties;
  }

  mraid.setExpandProperties = function(properties) {
  }

  mraid.expand = function(cb) {
  }

  mraid.setResizeProperties = function(properties) {
  }

  mraid.resize = function() {
  }

  mraid.getMaxSize = function() {
    return mraidData.maxSize;
  };
 
  mraid.getScreenSize = function() {
    return mraidData.screenSize;
  };

  mraid.getCurrentPosition = function() {
    return mraidData.currentPosition;
  };

  mraid.getDefaultPosition = function() {
    return mraidData.defaultPosition;
  };

  mraid.getCurrentAppOrientation = function() {
    return mraidData.currentAppOrientation;
  }

  mraid.getOrientationProperties = function() {
    return window.mraidData.orientationProperties;
  }

  mraid.setOrientationProperties = function(properties) {
  }

  mraid.getState = function() {
    return window.mraidData.state;
  }

  mraid.getPlacementType = function() {
    return window.mraidData.placementType;
  }

  mraid.storePicture = function(URI) {
  }

  mraid.createCalendarEvent = function(parameters) {
    window.webkit.messageHandlers.handler.postMessage({action: "createCalendarEvent", parameters: parameters});
  }

  mraid.open = function(url) {
    window.webkit.messageHandlers.handler.postMessage({action: "open", url: url});
  };

  mraid.close = function() {
    window.webkit.messageHandlers.handler.postMessage({action: "close"});
  };

  mraid.unload = function() {
    window.webkit.messageHandlers.handler.postMessage({action: "unload"});
  };

  mraid.playVideo = function(url) {
    window.webkit.messageHandlers.handler.postMessage({action: "playVideo", url: url});
  };

  mraid.fallback = function() {
    window.webkit.messageHandlers.handler.postMessage({action: "fallback"});
  };

  mraid.adLoaded = function() {
    window.webkit.messageHandlers.handler.postMessage({action: "adLoaded"});
  };

  mraid.useCustomClose = function(b) {
    window.webkit.messageHandlers.handler.postMessage({action: "useCustomClose", b: b});
  }

  mraid.addEventListener = function (ev, cb) {
    if (!this.evListeners.hasOwnProperty(ev)) {
      this.evListeners[ev] = [];
    }
    this.evListeners[ev].push(cb);
  }

  mraid.removeEventListener = function (ev, cb) {
    if (this.evListeners.hasOwnProperty(ev)) {
      if (typeof cb == 'undefined') {
        this.evListeners[ev] = [];
      } else {
        for (var i = 0; i < this.evListeners[ev].length; i++) {
          if (this.evListeners[ev][i] == cb) {
            this.evListeners[ev].splice(i, 1);
          }
        }
      }
    }
  }
}());
