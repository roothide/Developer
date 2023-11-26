//
//  FBSSystemService.h
//  Comet
//
//  Created by Noah Little on 9/4/2023.
//

#ifndef Respring_Private_h
#define Respring_Private_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, SBSRelaunchActionOptions) {
    SBSRelaunchActionOptionsNone,
    SBSRelaunchActionOptionsRestartRenderServer = 1 << 0,
    SBSRelaunchActionOptionsSnapshotTransition = 1 << 1,
    SBSRelaunchActionOptionsFadeToBlackTransition = 1 << 2
};

// MARK: - Underlying

@interface SBSRelaunchAction : NSObject
@end

@interface FBSSystemService : NSObject
@end

// MARK: - Facade

@interface _SBSRelaunchAction : NSObject
+ (instancetype)actionWithReason:(NSString *)reason options:(SBSRelaunchActionOptions)options targetURL:(nullable NSURL *)url;
@end

@interface _FBSSystemService : NSObject
+ (instancetype)sharedService;
- (void)openApplication:(NSString *)app options:(NSDictionary *)options withResult:(void (^)(void))result;
- (void)sendActions:(NSSet<_SBSRelaunchAction *> *)actions withResult:(nullable /*^block*/id)result;
@end

NS_ASSUME_NONNULL_END

#endif /* Respring_Private_h */
