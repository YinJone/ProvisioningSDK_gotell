//
//  ProvisioningSDK.h
//  ProvisioningSDK
//
//  Created by Alejandro Espinosa on 3/5/17.
//  Copyright © 2017 Fon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ProvisioningSDKDelegate.h"
#import "ProvisioningErrors.h"
#import "FPRManagedNetwork.h"
@import CocoaLumberjack;

//! Project version number for ProvisioningSDK.
FOUNDATION_EXPORT double ProvisioningSDKVersionNumber;

//! Project version string for ProvisioningSDK.
FOUNDATION_EXPORT const unsigned char ProvisioningSDKVersionString[];

#undef LOG_LEVEL_DEF
#define LOG_LEVEL_DEF ProvisioningSDKLogLevel
FOUNDATION_EXPORT DDLogLevel const ProvisioningSDKLogLevel;

/**
 Provision the phone with networks that can connect depending of a particular provider and user.
 */
@interface ProvisioningSDK : NSObject

/**
 Desired initializer to create the ProvisioningSDK instance.
 
 @warning The instance of the ProvisioningSDK should be unique. We recommend to create it in the AppDelegate an access to it, or wrap it in a Singleton.
 
 @param delegate Delegate used to obtain the credentials.
 @return Instance of ProvisioningSDK.
 */
- (instancetype)initWithDelegate:(id<ProvisioningSDKDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/**
 Delegate of the ProvisioningSDK class.
 */
@property (weak, nonatomic) id<ProvisioningSDKDelegate> delegate;

/**
 Set up the client id and client secret that the framework needs to work.
 
 @param clientID The client id of the provider.
 @param clientSecret The client secret of the provider.
 */
- (void)provideClientID:(NSString *)clientID clientSecret:(NSString *)clientSecret;

/**
 Provision the phone with networks that can connect depending of a particular provider and user.
 
 @param completion A block object to be executed when the task finishes. This block has no return value and takes two arguments: a BOOL indicating if we need to update the mobile config file, and an error in case it finishes unsuccessfully describing the error that occurred.
 */
- (void)provisionVNPWithCompletion:(void (^)(BOOL mustUpdateMobileConfig, NSError *error))completion;

/**
 Return if a network is managed by our framework.
 
 @param ssid to check if it is managed.
 @return FPRManagedNetworkTypeOpen if the network is managed of type open, FPRManagedNetworkTypeEAP if the network is managed of type EAP, FPRManagedNetworkTypeNone otherwise.
 */
- (FPRManagedNetworkType)isNetworkManaged:(NSString *)ssid;

/**
 Return VNPs of SSID.
 
 @param ssid search VNPS
 @return NSArray of VNPs
 */
- (NSArray<NSString*> *)vnpsSsid:(NSString *)ssid;

/**
 Return the array of FPRManagedNetwork instances managed by our framework.
 
 @return Array of FPRManagedNetwork instances managed by our framework.
 */
- (NSArray *)managedNetworks;

/**
 Return the URL that contains the mobile config provisioning, this URL must be opened in Safari so the user can download it.
 
 @param country for all Countries set nil
 @param completion A block object to be executed when the task finishes. This block has no return value and takes two arguments: the URL that contains the mobile config provisioning, and an error in case it finishes unsuccessfully describing the error that occurred.
 */
- (void)mobileConfigURLWithURLScheme: (NSString*) urlScheme country:(NSString *)country completion:(void (^)(NSString *mobileConfigURL, NSError *error))completion;
- (void)mobileConfigURLWithURLScheme: (NSString*) urlScheme countries:(NSArray<NSString*> *)countries completion:(void (^)(NSString *mobileConfigURL, NSError *error))completion;

/**
 Return if a mobile config provisioning file is installed in the device.
 
 @return YES if a mobile config provisioning file is installed in the device, NO otherwise.
 */
- (BOOL)isMobileConfigInstalled;

/**
 Return the modified username from the provision vnp so we can connect to the WISPr.
 
 @return Modified username from the provision vnp so we can connect to the WISPr.
 */
- (NSString *)username;

/**
 Clear the provisioning configuration, this includes all internal data and all the managed networks.
 
 @warning The mobile config must be removed manually.
 
 @return YES if we could remove the provisioning, NO otherwise.
 */
- (BOOL)removeProvisioning;

/**
 Create user with phone number
 
 @param phone The phone number
 @param completion This block return an error in case it finishes unsuccessfully describing the error that occurred.
 */
- (void)createUserWithPhone: (NSString*)phone completion:(void (^)(NSError *error))completion;

/**
 Validate user and return Username and secret
 
 @param phone The phone number
 @param completion This block return the username and secret and an error in case it finishes unsuccessfully describing the error that occurred.
 */
- (void)validateUserWithPhone: (NSString*) phone code:(NSString*)code completion:(void (^)(NSString *username, NSString *secret, NSError *error))completion;

@end
