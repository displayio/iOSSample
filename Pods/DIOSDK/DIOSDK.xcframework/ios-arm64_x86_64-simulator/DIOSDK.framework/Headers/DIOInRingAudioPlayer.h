
#import <DIOSDK/DIOMediaPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInRingAudioPlayer : DIOMediaPlayer


//todo clean redundant
- (void)close;
- (void)pause;
- (void)play;
//- (void)toggleSound:(BOOL) isEnabled; //todo switch audio output

@end

NS_ASSUME_NONNULL_END
