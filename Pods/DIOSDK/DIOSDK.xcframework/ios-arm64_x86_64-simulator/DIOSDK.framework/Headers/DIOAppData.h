//
//  DIOAppData.h
//  DIOSDK
//
//  Created by Ro Do on 05.01.2024.
//  Copyright © 2024 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//producer
@interface DIOContentProducer: NSObject

@property (nonatomic, strong) NSString *id_;
@property (nonatomic, strong) NSString *name_;
@property (nonatomic, strong) NSArray<NSString*> *cat_;
@property (nonatomic, strong) NSString *domain_;
@property (nonatomic, strong) id ext_;

- (NSMutableDictionary*)body;
@end

//segment for additional data
@interface DIOContentDataSegment: NSObject

@property (nonatomic, strong) NSString* id_;
@property (nonatomic, strong) NSString* name_;
@property (nonatomic, strong) NSString* value_;
@property (nonatomic, strong) id ext_;

- (NSMutableDictionary*)body;
@end

//additional data
@interface DIOContentData: NSObject

@property (nonatomic, strong) NSString* id_;
@property (nonatomic, strong) NSString* name_;
@property (nonatomic, strong) NSArray<DIOContentDataSegment*>* segment_;
@property (nonatomic, strong) id ext_;

- (NSMutableDictionary*)body;
@end


@interface DIOAppData : NSObject

- (NSMutableDictionary*)body;
- (void)setCat:(NSArray<NSString*>*)cat;
- (void)setSectionCats:(NSArray<NSString*>*)sectionCats;
- (void)setPageCat:(NSArray<NSString*>*)pageCat;
- (void)setAppVersion:(NSString*)appVersion;
- (void)setPrivacyPolicy:(NSNumber*)policy;
- (void)setPaid:(NSNumber*)paid;
- (void)setStoreUrl:(NSString*)storeUrl;
- (void)setDomain:(NSString*)domain;
- (void)setPublisherCats:(NSArray<NSString*>*)publisherCats;

- (void)setContentId:(NSString*)contentId;
- (void)setContentEpisode:(NSNumber*)episode;
- (void)setContentTitle:(NSString*)title;
- (void)setContentSeries:(NSString*)series;
- (void)setContentSeason:(NSString*)season;
- (void)setContentArtist:(NSString*)artist;
- (void)setContentGenre:(NSString*)genre;
- (void)setContentAlbum:(NSString*)album;
- (void)setContentIsrc:(NSString*)isrc;
- (void)setContentProducer:(DIOContentProducer*)producer;
- (void)setContentUrl:(NSString*)contentUrl;
- (void)setContentCat:(NSArray<NSString*>*)cat;
- (void)setContentProdq:(NSNumber*)prodq;
- (void)setContentContext:(NSNumber*)context;
- (void)setContentRating:(NSString*)contentRating;
- (void)setContentUserrating:(NSString*)contentUserrating;
- (void)setContentQagmediarating:(NSNumber*)qagmediarating;
- (void)setContentKeywords:(NSString*)contentKeywords;
- (void)setContentLivestream:(NSNumber*)livestream;
- (void)setContentSourcerelationship:(NSNumber*)sourcerelationship;
- (void)setContentLen:(NSNumber*)len;
- (void)setContentLanguage:(NSString*)language;
- (void)setContentEmbeddable:(NSNumber*)embeddable;
- (void)setContentData:(NSArray<DIOContentData*>*)contentData;
@end

NS_ASSUME_NONNULL_END
