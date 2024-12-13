
#import <DIOSDK/DIOMediaPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInRingAudioPlayer : DIOMediaPlayer

- (void)close;
- (void)pause;
- (void)play;

@end

NS_ASSUME_NONNULL_END
