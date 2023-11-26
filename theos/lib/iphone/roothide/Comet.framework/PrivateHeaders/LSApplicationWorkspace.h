//
//  LSApplicationWorkspace.h
//  Comet
//
//  Created by Noah Little on 9/4/2023.
//

#ifndef LSApplicationWorkspace_h
#define LSApplicationWorkspace_h

#import <Foundation/Foundation.h>
#import <MobileCoreServices/MobileCoreServices.h>

// MARK: - Underlying

NS_ASSUME_NONNULL_BEGIN
@interface LSApplicationRecord : NSObject
@property (readonly) NSArray<NSString *> * appTags;
@property (getter=isLaunchProhibited,readonly) BOOL launchProhibited;
@end

@interface LSResourceProxy: NSObject
@property (setter=_setLocalizedName:,nonatomic,copy) NSString * localizedName;
@end

@interface LSApplicationProxy : LSResourceProxy
@property (nonatomic,readonly) NSString * applicationIdentifier;
@property (nonatomic,readonly) LSApplicationRecord * correspondingApplicationRecord;
@property (nonatomic,readonly) NSString * applicationType;
+ (nullable instancetype)applicationProxyForIdentifier:(NSString *)identifier;
@end

@interface LSApplicationWorkspace : NSObject
+ (instancetype)defaultWorkspace;
- (nullable NSArray<LSApplicationProxy *> *)allApplications;
@end
NS_ASSUME_NONNULL_END
#endif /* LSApplicationWorkspace_h */
