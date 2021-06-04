/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents possible results of a Firebase App Check token refresh attempt that matter for `FIRAppCheckTokenRefresher`.
typedef NS_ENUM(NSInteger, FIRAppCheckTokenRefreshStatus) {
  // The token has not been refreshed.
  FIRAppCheckTokenRefreshStatusNever,

  // The token was successfully refreshed.
  FIRAppCheckTokenRefreshStatusSuccess,

  // The token refresh failed.
  FIRAppCheckTokenRefreshStatusFailure
};

/// An object to pass the possible results of a Firebase App Check token refresh attempt and supplementary data.
@interface FIRAppCheckTokenRefreshResult : NSObject

/// Status of the refresh.
@property(nonatomic, readonly) FIRAppCheckTokenRefreshStatus status;

/// A date when the new Firebase App Check token is expiring.
@property(nonatomic, readonly, nullable) NSDate *tokenExpirationDate;

/// A date when the new Firebase App Check token was received from the server.
@property(nonatomic, readonly, nullable) NSDate *tokenReceivedAtDate;

- (instancetype)init NS_UNAVAILABLE;

/// Initializes the instance with `FIRAppCheckTokenRefreshStatusNever`.
- (instancetype)initWithStatusNever;

/// Initializes the instance with `FIRAppCheckTokenRefreshStatusFailure`.
- (instancetype)initWithStatusFailure;

/// Initializes the instance with `FIRAppCheckTokenRefreshStatusFailure`.
/// @param tokenExpirationDate See `tokenExpirationDate` property.
/// @param tokenReceivedAtDate See `tokenReceivedAtDate` property.
- (instancetype)initWithStatusSuccessAndExpirationDate:(NSDate *)tokenExpirationDate receivedAtDate:(NSDate *)tokenReceivedAtDate;

@end

NS_ASSUME_NONNULL_END