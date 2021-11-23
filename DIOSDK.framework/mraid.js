(function () {
    var mraid = window.mraid = {};
    var mraidData = window.mraidData = {};

    //////////////////////////////////////////////////////////////////////////////////////////////////

    window.mraidBridge = {};

    window.mraidBridge.setSupportProperties = function (supportProperties) {
        mraidData.supportProperties = supportProperties;
    }

    window.mraidBridge.setExpandProperties = function (width, height, useCustomClose, isModal) {
        console.log("window.mraidBridge.setExpandProperties called with data:");
        console.log({
            width: width,
            height: height,
            useCustomClose: useCustomClose,
            isModal: isModal
        });

        mraidData.expandProperties = {
            width: width,
            height: height,
            useCustomClose: useCustomClose,
            isModal: isModal
        };
    };

    window.mraidBridge.setMaxSize = function (width, height) {
        console.log("window.mraidBridge.setMaxSize called with data:");
        console.log({
            width: width,
            height: height
        });


        mraidData.maxSize = {
            width: width,
            height: height
        };
    };

    window.mraidBridge.setScreenSize = function (width, height) {
        console.log("window.mraidBridge.setScreenSize called with data:")
        console.log({
            width: width,
            height: height
        });

        mraidData.screenSize = {
            width: width,
            height: height
        };
    };

    window.mraidBridge.setCurrentPosition = function (x, y, width, height) {
        console.log("window.mraidBridge.setCurrentPosition called with data:")
        console.log({
            x: x,
            y: y,
            width: width,
            height: height
        });

        mraidData.currentPosition = {
            x: x,
            y: y,
            width: width,
            height: height
        };
    };

    window.mraidBridge.setDefaultPosition = function (x, y, width, height) {
        console.log("window.mraidBridge.setDefaultPosition called with data:")
        console.log({
            x: x,
            y: y,
            width: width,
            height: height
        });

        mraidData.defaultPosition = {
            x: x,
            y: y,
            width: width,
            height: height
        };
    };

    window.mraidBridge.setCurrentAppOrientation = function (orientation, locked) {
        console.log("window.mraidBridge.setCurrentAppOrientation called with data:")
        console.log({
            orientation: orientation,
            locked: locked
        });

        mraidData.currentAppOrientation = {
            orientation: orientation,
            locked: locked
        };
    };

    window.mraidBridge.setOrientationProperties = function (allowOrientationChange, forceOrientation) {
        console.log("window.mraidBridge.setOrientationProperties called with data:")
        console.log({
            allowOrientationChange: allowOrientationChange,
            forceOrientation: forceOrientation
        });

        mraidData.orientationProperties = {
            allowOrientationChange: allowOrientationChange,
            forceOrientation: forceOrientation
        };
    };

    window.mraidBridge.triggerEvent = function (ev, params) {

        if (ev != 'exposureChange') {
            console.log("window.mraidBridge.triggerEvent called with data:")
            console.log({event: ev, params: params});

        }
        
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

    mraid.getVersion = function () {
        console.log("mraid.getVersion called and returned:")
        console.log(mraid.VERSION);

        return mraid.VERSION;
    }

    mraid.isViewable = function () {
        console.log("mraid.isViewable called and returned:")
        console.log(window.mraidData.isViewable);

        return window.mraidData.isViewable;
    }

    mraid.supports = function (feature) {
        console.log("mraid.supports called for the feature:")
        console.log(feature);
        console.log("and returned:")
        console.log(window.mraidData.supportProperties[feature]);

        return window.mraidData.supportProperties[feature];
    };

    mraid.getExpandProperties = function () {
        console.log("mraid.getExpandProperties called and returned:")
        console.log(window.mraidData.expandProperties);

        return window.mraidData.expandProperties;
    }

    mraid.setExpandProperties = function (properties) {
        console.log("mraid.setExpandProperties called with data:")
        console.log(properties);
        console.warn('BUT THIS IS STUB METHOD');

    }

    mraid.expand = function (cb) {
        console.log("mraid.expand called with properties:")
        console.log(cb);
        console.warn('BUT THIS IS STUB METHOD');

    }

    mraid.setResizeProperties = function (properties) {
        console.log("mraid.setResizeProperties called with data:")
        console.log(properties);
        console.warn('BUT THIS IS STUB METHOD');

    }

    mraid.resize = function () {
        console.log("mraid.resize called")
        console.warn('BUT THIS IS STUB METHOD');
    }

    mraid.getMaxSize = function () {
        console.log("mraid.getMaxSize called and returned:")
        console.log(mraidData.maxSize);

        return mraidData.maxSize;
    };

    mraid.getScreenSize = function () {
        console.log("mraid.getScreenSize called and returned:")
        console.log(mraidData.screenSize);

        return mraidData.screenSize;
    };

    mraid.getCurrentPosition = function () {
        console.log("mraid.getCurrentPosition called and returned:")
        console.log(mraidData.currentPosition);

        return mraidData.currentPosition;
    };

    mraid.getDefaultPosition = function () {
        console.log("mraid.getDefaultPosition called and returned:")
        console.log(mraidData.defaultPosition);

        return mraidData.defaultPosition;
    };

    mraid.getCurrentAppOrientation = function () {
        console.log("mraid.getCurrentAppOrientation called and returned:")
        console.log(mraidData.currentAppOrientation);

        return mraidData.currentAppOrientation;
    }

    mraid.getOrientationProperties = function () {
        console.log("mraid.getOrientationProperties called and returned:")
        console.log(window.mraidData.orientationProperties);

        return window.mraidData.orientationProperties;
    }

    mraid.setOrientationProperties = function (properties) {
        console.log("mraid.setOrientationProperties called with data:")
        console.log(properties);
        console.warn('BUT THIS IS STUB METHOD');

    }

    mraid.getState = function () {
        console.log("mraid.getState called and returned:")
        console.log(window.mraidData.state);

        return window.mraidData.state;
    }

    mraid.getPlacementType = function () {
        console.log("mraid.getPlacementType called and returned:")
        console.log(window.mraidData.placementType);

        return window.mraidData.placementType;
    }

    mraid.storePicture = function (URI) {
        console.log("mraid.storePicture called with data:")
        console.log(URI);
        console.warn('BUT THIS IS STUB METHOD');

    }

    mraid.createCalendarEvent = function (parameters) {
        console.log("mraid.createCalendarEvent called with data:")
        console.log(parameters);

        window.webkit.messageHandlers.handler.postMessage({action: "createCalendarEvent", parameters: parameters});
    }

    mraid.open = function (url) {
        console.log("mraid.open called with data:")
        console.log(url);

        window.webkit.messageHandlers.handler.postMessage({action: "open", url: url});
    };

    mraid.close = function () {
        console.log("mraid.close called")

        window.webkit.messageHandlers.handler.postMessage({action: "close"});
    };

    mraid.unload = function () {
        console.log("mraid.unload called")

        window.webkit.messageHandlers.handler.postMessage({action: "unload"});
    };

    mraid.playVideo = function (url) {
        console.log("mraid.playVideo called with data:")
        console.log(url);

        window.webkit.messageHandlers.handler.postMessage({action: "playVideo", url: url});
    };

    mraid.fallback = function () {
        console.log("mraid.fallback called")

        window.webkit.messageHandlers.handler.postMessage({action: "fallback"});
    };

    mraid.adLoaded = function () {
        console.log("mraid.adLoaded called")

        window.webkit.messageHandlers.handler.postMessage({action: "adLoaded"});
    };

    mraid.useCustomClose = function (b) {
        console.log("mraid.useCustomClose called with data:")
        console.log(b);

        window.webkit.messageHandlers.handler.postMessage({action: "useCustomClose", b: b});
    }

    mraid.addEventListener = function (ev, cb) {
        console.log("mraid.addEventListener called with data:")
        console.log({event:ev, callback:cb});

        if (!this.evListeners.hasOwnProperty(ev)) {
            this.evListeners[ev] = [];
        }
        this.evListeners[ev].push(cb);
    }

    mraid.removeEventListener = function (ev, cb) {
        console.log("mraid.removeEventListener called with data:")
        console.log({event:ev, callback:cb});

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
